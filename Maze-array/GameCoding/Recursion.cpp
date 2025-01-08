#include <iostream>
using namespace std;

// Vector/List/��� -> Tree -> Graph -> BFS -> Dijikstra -> A* (PQ)

// [                          ]
// �Լ��� ȣ�� �� ������ �Ҵ��ϰ� �����Ҷ� ��ȯ�Ǿ�� �ϴµ� ����Լ��� ��ȯ�� ���� �ʾ�
// ������ ����ϴ� ������ �Ѿ�� ������ Stackoverflow�� �����
void Func(int a)
{
	if (!a)
		return;

	cout << a << endl;

	Func(a - 1);
}

// 5! = 5x4x3x2x1 = 5 x 4! = 120
// n! = n x n-1 x ... 1 = n x (n - 1)!

int Factorial(int n)
{
	if (n <= 1)
		return 1;

	return n * Factorial(n - 1);
}

// ��Ŭ���� �˰��� - �ִ�����
// a > b
// GCD(1071, 1029)
// = GCD(1029, 1071%1029 = 42)
// = GCD(42, 1029%42 = 21)
// = GCD(21, 0) = 21
int GCD(int a, int b)
{
	if (!b)
		return a;

	return GCD(b, a % b);
}

int main()
{
	Func(5);

	int gcd = GCD(1071, 1029);
	cout << "gcd: " << gcd << endl;
}