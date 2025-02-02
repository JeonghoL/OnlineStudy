#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
using namespace std;

// auto

class Knight
{

};

template <typename T>
void Print(T t)
{
	cout << t << endl;
}

int main()
{
	// auto
	// - ���� : Ÿ����
	// - ���� : ������ X

	// C++03
	// C++11 (Modern C++)
	// C++14
	// C++17
	// C++20

	{
		int a = 3;
		float b = 3.14f;
		double c = 1.23;
		Knight* d = new Knight();
		const char* e = "Rookiss";
	}

	vector<int> v;
	auto it = v.begin();

	map<int, int> m;
	// std::map<int, int>::iterator it = m.begin();
	auto it2 = m.begin();

	{
		auto a = 3;
		auto b = 3.14f;
		auto c = 1.23;
		auto d = new Knight();
		auto e = "Rookiss";

		// auto�� ������ ��Ŀ ī��
		Print<int>(1);
		Print<const char*>("Rookiss");
		// ���� ���� (type deduction)
		// -> ���� �ǰ� �� �����? �߷�

		int& ref = a;
		const int cst = a;

		// ����! auto�� const, &�� ���� �߷��Ѵ�
		auto& ref2 = ref;
		const auto cst2 = cst;

		vector<int> v{ 1, 2, 3, 4, 5 };

		for (int i = 0; i < v.size(); ++i)
		{
			auto& value = v[i];

			if (value < 5)
			{
				value = 10;
			}
		}

	}
}