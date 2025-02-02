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
	// - 장점 : 타이핑
	// - 단점 : 가독성 X

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

		// auto는 일종의 조커 카드
		Print<int>(1);
		Print<const char*>("Rookiss");
		// 형식 연역 (type deduction)
		// -> 말이 되게 잘 맞춰봐? 추론

		int& ref = a;
		const int cst = a;

		// 주의! auto는 const, &는 떼고 추론한다
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