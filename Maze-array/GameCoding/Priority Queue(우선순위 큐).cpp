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
		// �켱 �� �������� �����ش�. (������ �߰� �� �� �ڿ� �߰��ȴ�.)
		_heap.push_back(data);

		// ������� ����
		int now = static_cast<int>(_heap.size()) - 1;

		// ��Ʈ ������
		while (now > 0)
		{
			// �θ� ���� ���ؼ� �� ������ �й�
			int next = (now - 1) / 2;
			// �ִ� ������
			// if (_heap[now] < _heap[next])
			// break;
			// 
			// �ּ� ������
			if (_predicate(_heap[now], _heap[next]))
				break;

			// ������ ��ü
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

			// ������ ������ ���
			if (left >= (int)_heap.size())
				break;

			int next = now;

			// ���� ��
			if (_heap[next] < _heap[left])
				next = left;

			// �� �� ���ڸ� �����ʰ� ��
			// �ִ� ���� ��
			// if (right < _heap.size() && _heap[next] < _heap[right])
			//	 next = right;

			// �ּ� ���� ��
			if (right < _heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;

			// ����/������ �� �� ���� ������ ������ ����
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


// �켱 ���� ť - ���� ���� ���̽� �ϳ��� ���� �ؾ� �ϴ� ��쿡 �����ϴ�.
int main()
{
	vector<int> v;
	PriorityQueue<int, greater<int>> pq;

	// ǥ�� �ִ� �̱�
	//priority_queue<int, vector<int>, less<int>> pq;
	// ǥ�� �ּ� �̱�
	//priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(10);
	pq.push(40);
	pq.push(30);
	pq.push(50);
	pq.push(20);

	int value = pq.top();
	pq.pop();

	// [][][][][][][][][][] v�� ���� �������� �ִٴ� ����,
	// �� �߿� �ϳ��� �̾ƾ� �Ҷ�
	// �����ؼ� ���ϸ� O(NlogN)
	// ���� ���ϰ� �ϳ��� üũ�ؼ� ���ϸ� O(N)
	// �켱 ������ �Ⱦ��� �ּ� O(N)
	// �켱 ���� ť�� ����ϸ� �� ȿ����.
	
	// �� Ʈ�� ��Ģ 2���� (���� ū ���ڸ� �̾� ������ �Ҷ�)
	// 1. �θ� ��尡 ���� ���� �׻� �ڽ� ��尡 ���� ������ ũ��.
	// 2. ��� ������ �˸�, Ʈ�� ������ ������ Ȯ�� �� �� �ִ�.
	// (������ ������ ������ ��� ������ �׻� ��尡 �� �־���ϰ�,
	// ������ ������ ���� ���ʺ��� ä������.)

	// ���� ���
	// [push]
	// 1. ������ ��忡 �����Ͱ� �߰���
	// 2. �θ� ���� �����
	// 3. ��ῡ�� �й��� ������ ��� �ö󰡸鼭 ����ϸ� ������ �ٲ�
	// 
	// [pop]
	// 1. �ֻ�� ����� ������ ����
	// 2. �� �ϴ� ��带 �� ������� �ϴ� ����
	// 3. �ֻ�ܿ� �ִ� ����� ��ġ�� �������鼭 �ٽ� ����

	// �� ���� ǥ��
	// 1. i�� ����� ���� �ڽ��� [(2 * i) + 1]��
	// 2. i�� ����� ������ �ڽ��� [(2 * i) + 2]��
	// 3. i�� ����� �θ�� [(i - 1) / 2]��

	// ������ �ִ� ���� ���� ���� ����ε�,
	// �ּ� ���� ���� ������ �Ѵٸ�
	// 1. (�ļ�?) push�� ���� ���� value ���� -�� �޸� ��
	// ����) pq.push(-10);	int value = -pq.top();
	// 2. ���� ������ �ڵ�ó�� Predicate�� less & greater ����ϸ� ��
	// 3. ǥ�� priority_queue ��� �� ��, 
	// priority_queue<int, vector<int>, greater<int>> �� ����
}