#include <iostream>
using namespace std;

// 함수 템플릿 - 실제로 타입별 함수들을 컴파일러가 직접 만들어서 호출하는 느낌

//// 조커카드 1개
//template<typename T>
//void Print(T a)
//{
//	cout << a << endl;
//}
//
//template<typename T1, typename T2>
//void Print(T1 a, T2 b)
//{
//	cout << a << " " << b << endl;
//}
//
//// 특정한 자료형은 특별히 사용하고 싶을 때
//template<>
//void Print(int a)
//{
//	cout << "int" << endl;
//}
//
//int main()
//{
//	Print(1);
//	Print(3.14);
//	Print("Hello World");
//	Print(1, "Rookiss");
//}



// 클래스 템플릿 - 런타임에서 결정되는게 아니라 컴파일러가 빌드 할 때 모든 것이 결정됨
//			   - 사용하지 않으면 만들지 않음

// 1. 템플릿 기초 문법
// 2. 특수화 템플릿 문법

// 아무것도 설정 안하면 기본 int, SIZE = 100
template<typename T = int, int SIZE = 100>
class RandomBox
{
public:
	T GetRandomData()
	{
		int index = rand() % SIZE;
		return data[index];
	}

public:
	T data[SIZE];
};

template<>
class RandomBox<int>
{
public:
	int GetRandomData()
	{
		int index = rand() % 100;
		return data[index];
	}

public:
	int data[100];
};

int main()
{
	RandomBox<int, 100> rb1;
	rb1.GetRandomData();
	RandomBox<float, 200> rb2;
	RandomBox<> rb3;
}