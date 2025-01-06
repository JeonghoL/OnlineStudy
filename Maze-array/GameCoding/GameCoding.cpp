#include <iostream>
using namespace std;

// �Լ� ���ø� - ������ Ÿ�Ժ� �Լ����� �����Ϸ��� ���� ���� ȣ���ϴ� ����

//// ��Ŀī�� 1��
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
//// Ư���� �ڷ����� Ư���� ����ϰ� ���� ��
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



// Ŭ���� ���ø� - ��Ÿ�ӿ��� �����Ǵ°� �ƴ϶� �����Ϸ��� ���� �� �� ��� ���� ������
//			   - ������� ������ ������ ����

// 1. ���ø� ���� ����
// 2. Ư��ȭ ���ø� ����

// �ƹ��͵� ���� ���ϸ� �⺻ int, SIZE = 100
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