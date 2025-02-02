#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "List.h"
using namespace std;

int main()
{
	// size (resize)
	// capacity (reserve)
	// 삽입/삭제?
	// - 시작			O(1)
	// - 중간			O(1) << 위치를 기억하고 있을 때
	// - 끝				O(1)
	// front			O(1)
	// back				O(1)
	// push_front		O(1)
	// push_back		O(1)
	// remove(value)
	// 임의 접근 li[2]

	list<int> li;
	li.push_front(10);
	li.push_front(20);
	li.push_front(30);

	list<int>::iterator it;

	for (it = li.begin(); it != li.end(); ++it)
	{
		int value = *it;

		if (value == 30)
			break;
	}

	cout << *it << endl;
}