#include <iostream>
using namespace std;

// Vector/List/재귀 -> Tree -> Graph -> BFS -> Dijikstra -> A* (PQ)

// [                          ]
// 함수는 호출 시 스택을 할당하고 종료할때 반환되어야 하는데 재귀함수는 반환을 하지 않아
// 스택이 허용하는 범위를 넘어서기 때문에 Stackoverflow가 생긴다
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

// 유클리드 알고리즘 - 최대공약수
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