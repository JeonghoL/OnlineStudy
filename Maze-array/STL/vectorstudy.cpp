#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

void Test(vector<int>& v)
{

}

int main()
{
	//vector<int> v{ 1, 2, 3, 4, 5 };
	// size (resize)
	// capacity (reserve)
	// ����/����
	// - ����	O(N)
	// - �߰�	O(N)
	// - ��		O(1)
	// push_back, front, back
	// ���� ���� v[i]		O(1)
	// v.remove(10)?

	//v.reserve(10);

	//v.push_back(10);
	//v.push_back(20);
	//v.push_back(30);

	//int a = v.front();	// O(1)
	//int b = v.back();	// O(1)

	// �߰�
	// ����
	// ��ȸ
	// �˻�

	//vector<int> v(5);
	//vector<int> v(5, -1);

	// [			]
	// []
	vector<int> v{ 1, 2, 3, 4, 5 };
	vector<int> v2 = v;

	//Test(v);

	//v2[0] = 100;
	v.clear();
	cout << v.size() << " " << v.capacity() << endl;
	// size		?
	// capacity ?

	//vector<int>().swap(v);	// �̰� ���� ���� ��

	{
		// Iterator ? �ݺ��� ������?
		/*vector<int> v{ 1, 2, 3, 4, 5 };

		int* ptr = &v[0];
		int* ptrEnd = &v[4] + 1;

		while (ptr != ptrEnd)
		{
			cout << *ptr << endl;
			ptr++;
		}*/
	}

	/*{
		list<int> v{ 1, 2, 3, 4, 5 };

		list<int>::iterator it = v.begin();
		list<int>::iterator itEnd = v.end();

		while (it != itEnd)
		{
			cout << *it << " ";
			it++;
		}
	}*/

	{
		vector<int> v{ 1, 2, 3, 4, 5 };

		/*vector<int>::iterator it = v.begin();
		vector<int>::iterator itEnd = v.end();

		while (it != itEnd)
		{
			cout << *it << " ";
			it++;
		}*/

		// 3?

		vector<int>::iterator it;

		//for (it = v.begin(); it != v.end(); ++it)
		//{
		//	int data = *it;
		//	if (data == 3)
		//	{
		//		// ã��
		//		break;
		//	}
		//	cout << data << endl;
		//}

		//if (it != v.end())
		//{
		//	cout << "ã��" << endl;
		//	v.erase(it);
		//}

		for (vector<int>::iterator it = v.begin(); it != v.end();)
		{
			int value = *it;

			// for�� ����ó�� ++it �ϸ� �ȵ�
			// �̷��� ���ǹ����� �������Ѿ���
			if (value % 2 == 0)
				it = v.erase(it);
			else
				it++;
		}

		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		{
			cout << *it << endl;
		}

	}
}