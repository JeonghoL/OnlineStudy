#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<typename T, typename Predicate = less<T>>
class PriorityQueue
{
public:
	// O(logN)
	void push(const T& data)
	{
		// 우선 힙 구조부터 맞춰준다. (데이터 추가 시 맨 뒤에 추가된다.)
		_heap.push_back(data);

		// 도장깨기 시작
		int now = static_cast<int>(_heap.size()) - 1;

		// 루트 노드까지
		while (now > 0)
		{
			// 부모 노드와 비교해서 더 작으면 패배
			int next = (now - 1) / 2;
			// 최대 뽑을때
			// if (_heap[now] < _heap[next])
			// break;
			// 
			// 최소 뽑을때
			if (_predicate(_heap[now], _heap[next]))
				break;

			// 데이터 교체
			swap(_heap[now], _heap[next]);
			now = next;
		}
	}
	
	// O(logN)
	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			// 리프에 도달할 경우
			if (left >= (int)_heap.size())
				break;

			int next = now;

			// 왼쪽 비교
			if (_heap[next] < _heap[left])
				next = left;

			// 둘 중 승자를 오른쪽과 비교
			// 최대 뽑을 때
			// if (right < _heap.size() && _heap[next] < _heap[right])
			//	 next = right;

			// 최소 뽑을 때
			if (right < _heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;

			// 왼쪽/오른쪽 둘 다 현재 값보다 작으면 종료
			if (next == now)
				break;

			swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	// O(1)
	T& top()
	{
		return _heap[0];
	}

	// O(1)
	bool empty()
	{
		return _heap.empty();
	}

private:
	vector<T> _heap;
	Predicate _predicate;
};


// 우선 순위 큐 - 가장 좋은 케이스 하나를 추출 해야 하는 경우에 유용하다.
int main()
{
	vector<int> v;
	PriorityQueue<int, greater<int>> pq;

	// 표준 최대 뽑기
	//priority_queue<int, vector<int>, less<int>> pq;
	// 표준 최소 뽑기
	//priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(10);
	pq.push(40);
	pq.push(30);
	pq.push(50);
	pq.push(20);

	int value = pq.top();
	pq.pop();

	// [][][][][][][][][][] v에 숫자 여러개가 있다는 가정,
	// 이 중에 하나를 뽑아야 할때
	// 정렬해서 구하면 O(NlogN)
	// 정렬 안하고 하나씩 체크해서 구하면 O(N)
	// 우선 순위를 안쓰면 최소 O(N)
	// 우선 순위 큐를 사용하면 더 효율적.
	
	// 힙 트리 규칙 2가지 (가장 큰 숫자를 뽑아 내려고 할때)
	// 1. 부모 노드가 가진 값은 항상 자식 노드가 가진 값보다 크다.
	// 2. 노드 개수를 알면, 트리 구조는 무조건 확정 할 수 있다.
	// (마지막 레벨을 제외한 모든 레벨은 항상 노드가 차 있어야하고,
	// 마지막 레벨의 노드는 왼쪽부터 채워진다.)

	// 동작 방식
	// [push]
	// 1. 마지막 노드에 데이터가 추가됨
	// 2. 부모 노드와 대결함
	// 3. 대결에서 패배할 때까지 계속 올라가면서 대결하며 데이터 바꿈
	// 
	// [pop]
	// 1. 최상단 노드의 데이터 추출
	// 2. 최 하단 노드를 최 상단으로 일단 설정
	// 3. 최상단에 있는 노드의 위치를 내려가면서 다시 잡음

	// 힙 구조 표현
	// 1. i번 노드의 왼쪽 자식은 [(2 * i) + 1]번
	// 2. i번 노드의 오른쪽 자식은 [(2 * i) + 2]번
	// 3. i번 노드의 부모는 [(i - 1) / 2]번

	// 지금은 최대 값을 꺼내 오는 방식인데,
	// 최소 값을 꺼내 오려고 한다면
	// 1. (꼼수?) push에 들어가는 값과 value 값에 -를 달면 됨
	// 예시) pq.push(-10);	int value = -pq.top();
	// 2. 지금 구성한 코드처럼 Predicate와 less & greater 사용하면 됨
	// 3. 표준 priority_queue 사용 할 시, 
	// priority_queue<int, vector<int>, greater<int>> 로 선언
}