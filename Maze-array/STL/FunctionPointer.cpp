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

// '행동' 자체를 인자로 넘기고 싶을 때
using FuncPtrType = int(*)(int a, int b);
int DoSomething(int a, int b, FuncPtrType func)
{
	return func(a, b);
}

// 콜백 함수
// - ex) UI
// - ex) 온라인 게임
// - ex) 키보드 입력
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

// 멤버 함수 포인터
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
	// 이렇게 독립적으로 사용하는 경우 거의 없음, 알아만 두자.

	// void(*FuncPtrType)();
	/*using FuncPtrType = void(*)();
	FuncPtrType ptr = &Print;
	ptr();

	ptr = &Print2;
	ptr();*/

	// 함수 포인터를 그래서 왜쓰냐?
	// '행동' 자체를 인자로 넘기고 싶을 때 사용
	DoSomething(10, 20, &Add);
	DoSomething(10, 20, [](int a, int b) { return a - b; });

	// 콜백 함수
	// if (Q버튼을 눌렀으면)
	//	QSkill();
	// 이런식으로 하면 예외 처리 너무 힘듦
	// 더 나은 방식
	/*using OnClickKeyBoard = void(*)();
	OnClickKeyBoard qSkill;
	if (qSkill && 대쉬)
		qSkill = &Teleport;
	else
		qSkill = &Fire;
	qSkill();*/

	Item items[10];
	items[3]._itemId = 3;	// RARE
	items[3]._rarity = 1;	// RARE
	items[3]._ownerId = 5;	// RARE

	Item* i = FindItem(items, 10, IsRare);


	// 멤버 함수 포인터 (정적/전역 함수랑 다르다)
	// 함수 호출 규약
	// 함수 호출 규약이 다르기 때문에 아래와 같이 설정 불가
	// cdecl(일반 함수), thiscall(멤버 함수)
	/*using FuncPtrType = void(*)();
	FuncPtrType func = &Test::PrintTest;
	Test t;
	t.PrintTest();*/
	// 아래와 같이 사용해야 함
	using MemFuncPtrType = void(Test::*)();
	MemFuncPtrType funcPtr = &Test::PrintTest;
	//funcPtr();	// 특정 객채를 대상으로 실행하는 것이므로 이렇게 실행 불가
	Test t;
	(t.*funcPtr)();

	Test* t2 = &t;
	(t2->*funcPtr)();	// 이딴거 언제쓰냐? - 서버에서 가끔 사용함
	// ex) 클라 -> 나 10번 유저 공격할래
	// ex) 클라2 -> 나 10, 20 좌표로 이동할래
	// ex) 클라3 -> 나 (20, 30) 덧셈을 해보고 싶어?
	// ..................
	// 서버는 주문서를 기준으로 처리 -> 함수 포인터 중요 (어떤 동작을 담을 수 있음)
	// but, 정보를 담아 줄 수 없음.
	using FuncPtrType2 = int(*)(int, int);
	FuncPtrType2 func = Add;
	int x = 20;
	int y = 30;
	func(x, y);		// 수치는 게임 상 매번 바뀌는데, 함수 포인터만으로는 데이터를 묶어서 관리 불가함 (Binding이 안됨)
					// 이를 위해 '함수 객체, 함수자, Functor'를 사용
}