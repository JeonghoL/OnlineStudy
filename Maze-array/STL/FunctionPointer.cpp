#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Print()
{
	cout << "Hello World" << endl;
}

void Print2()
{
	cout << "World Hello" << endl;
}

int Add(int a, int b)
{
	return a + b;
}

// '�ൿ' ��ü�� ���ڷ� �ѱ�� ���� ��
using FuncPtrType = int(*)(int a, int b);
int DoSomething(int a, int b, FuncPtrType func)
{
	return func(a, b);
}

// �ݹ� �Լ�
// - ex) UI
// - ex) �¶��� ����
// - ex) Ű���� �Է�
void Fire()
{

}

void Teleport()
{

}

class Item
{
public:

public:
	int _itemId = 0;
	int _rarity = 0;
	int _ownerId = 0;
};

using ItemSelectorType = bool(*)(Item* item);
Item* FindItem(Item items[], int itemCount, ItemSelectorType selector)
{
	for (int i = 0; i < itemCount; ++i)
	{
		Item* item = &items[i];
		if (selector(item))
			return item;
	}
}

bool IsRare(Item* item)
{
	return item->_rarity == 1;
}

// ��� �Լ� ������
class Test
{
public:
	void PrintTest() { a = 1; }

	int a;
};

int main()
{
	//using DataType = int;

	//// typedef void FuncType();
	//using FuncType = void();
	//FuncType* ptr = &Print;

	//ptr();

	//using FuncType2 = int(int, int);
	//FuncType2* ptr2 = &Add;

	//int ret = ptr2(1, 2);
	// �̷��� ���������� ����ϴ� ��� ���� ����, �˾Ƹ� ����.

	// void(*FuncPtrType)();
	/*using FuncPtrType = void(*)();
	FuncPtrType ptr = &Print;
	ptr();

	ptr = &Print2;
	ptr();*/

	// �Լ� �����͸� �׷��� �־���?
	// '�ൿ' ��ü�� ���ڷ� �ѱ�� ���� �� ���
	DoSomething(10, 20, &Add);
	DoSomething(10, 20, [](int a, int b) { return a - b; });

	// �ݹ� �Լ�
	// if (Q��ư�� ��������)
	//	QSkill();
	// �̷������� �ϸ� ���� ó�� �ʹ� ����
	// �� ���� ���
	/*using OnClickKeyBoard = void(*)();
	OnClickKeyBoard qSkill;
	if (qSkill && �뽬)
		qSkill = &Teleport;
	else
		qSkill = &Fire;
	qSkill();*/

	Item items[10];
	items[3]._itemId = 3;	// RARE
	items[3]._rarity = 1;	// RARE
	items[3]._ownerId = 5;	// RARE

	Item* i = FindItem(items, 10, IsRare);


	// ��� �Լ� ������ (����/���� �Լ��� �ٸ���)
	// �Լ� ȣ�� �Ծ�
	// �Լ� ȣ�� �Ծ��� �ٸ��� ������ �Ʒ��� ���� ���� �Ұ�
	// cdecl(�Ϲ� �Լ�), thiscall(��� �Լ�)
	/*using FuncPtrType = void(*)();
	FuncPtrType func = &Test::PrintTest;
	Test t;
	t.PrintTest();*/
	// �Ʒ��� ���� ����ؾ� ��
	using MemFuncPtrType = void(Test::*)();
	MemFuncPtrType funcPtr = &Test::PrintTest;
	//funcPtr();	// Ư�� ��ä�� ������� �����ϴ� ���̹Ƿ� �̷��� ���� �Ұ�
	Test t;
	(t.*funcPtr)();

	Test* t2 = &t;
	(t2->*funcPtr)();	// �̵��� ��������? - �������� ���� �����
	// ex) Ŭ�� -> �� 10�� ���� �����ҷ�
	// ex) Ŭ��2 -> �� 10, 20 ��ǥ�� �̵��ҷ�
	// ex) Ŭ��3 -> �� (20, 30) ������ �غ��� �;�?
	// ..................
	// ������ �ֹ����� �������� ó�� -> �Լ� ������ �߿� (� ������ ���� �� ����)
	// but, ������ ��� �� �� ����.
	using FuncPtrType2 = int(*)(int, int);
	FuncPtrType2 func = Add;
	int x = 20;
	int y = 30;
	func(x, y);		// ��ġ�� ���� �� �Ź� �ٲ�µ�, �Լ� �����͸����δ� �����͸� ��� ���� �Ұ��� (Binding�� �ȵ�)
					// �̸� ���� '�Լ� ��ü, �Լ���, Functor'�� ���
}