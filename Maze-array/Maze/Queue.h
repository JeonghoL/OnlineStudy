#pragma once
#include "Vector.h"

// [front/back][][][][][][][][][]
// <---------> 데이터 영역
// [front][][][back][][][][][][]
//   <-------> 데이터 영역
// [][front][][back][][][][][][]
// [front][][][back][][][][][][]
template<typename T>
class Queue
{
public:
	Queue()
	{
		_container.resize(100);
	}

	void push(const T& value)
	{
		// TODO : 다 찼는지 체크
		if (_size == _container.size())
		{

		}

		// 환형 Queue 설정 (back이 범위 밖으로 나갔을 때,
		// 맨 앞으로 돌아옴
		_container[_back] = value;
		_back = (_back + 1) % _container.size();
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }

private:
	Vector<T> _container;

	int _front = 0;
	int _back = 0;
	int _size = 0;
};