#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// �Լ� ��ü
// �Լ� �������� ����
// - �ñ״�ó�� �� ������ ��� �Ұ�
// - ���¸� ���� �� ����

class Functor
{
public:
	void operator()()
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	void operator()(int n)
	{
		cout << "Functor Test" << endl;
		_value += n;
		cout << _value << endl;
	}

public:
	int _value = 0;
};

// Functor�� ����
struct AddStruct
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

template<typename T>
int DoSomething(int a, int b, T func)
{
	return func(a, b);
}

template<typename T>
struct Greater
{
	bool operator()(const T& left, const T& right) const
	{
		return left > right;
	}
};

class Job
{
public:
	Job() { }
	virtual ~Job() { }
};

class MoveJob : public Job
{
public:
	MoveJob(int x, int y) : x(x), y(y){}

	void operator()()
	{
		cout << "player move ó��" << endl;
	}

public:
	int x;
	int y;
};

class AttackJob : public Job
{
public:
	AttackJob(int power) : power(power) {}

	void operator()()
	{
		cout << "player attack ó��" << endl;
	}

public:
	int power;
};

int main()
{
	Functor func;
	func._value = 10;
	func();
	func(10);

	AddStruct funct;
	DoSomething(10, 20, funct);

	priority_queue<int, vector<int>, Greater<int>> pq;

	// Ŭ�� : (10, 20) ��ǥ�� �̵��ҷ� ?
	MoveJob* job = new MoveJob(10, 20);
	AttackJob* attackJob = new AttackJob(5);
	//
	// ...
	queue<Job*>;
	(*job)();
}