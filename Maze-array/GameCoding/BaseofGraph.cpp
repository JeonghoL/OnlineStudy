#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Tree�� ���� �������� ��� (������ ��� ����)
void CreateGraph_1()
{
	struct Vertex
	{
		vector<Vertex*> edges;

	};

	//vector<Vertex> v;
	//v.resize(6);	// size
	//{
	//	v.push_back(Vertex());
	//	v.push_back(Vertex());
	//	v.push_back(Vertex());
	//	v.push_back(Vertex());
	//	v.push_back(Vertex());
	//	v.push_back(Vertex());
	//}

	//v.reserve(6);	// capacity
	//{
	//	// ���� 6��ŭ Ȯ��
	//}

	//vector<int> v2(10, -1);		// ������ ����, �ʱⰪ
	//vector<int> v3{ 1, 2, 3, 4, 5, 6, 7 };		// ������ �ʱ�ȭ

	vector<Vertex> v(6);
	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);

	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);

	v[3].edges.push_back(&v[4]);

	v[5].edges.push_back(&v[4]);

	// Q) 0�� -> 3���� ����Ǿ� �ֳ���?
	bool connected = false;

	int size = v[0].edges.size();
	for (int i = 0; i < size; ++i)
	{
		Vertex* vertex = v[0].edges[i];
		if (vertex == &v[3])
			connected = true;
	}
}

// �׷��� �����
// ex) ������ 100���� ���
// - ����ö �뼱�� -> ���� �幮 �幮 ����
// - ���̽��� ģ�� -> ���� �����ϰ� ����

// ��������Ʈ: ���� ����� �ֵ�'��' �־��ش�
// ����ö �뼱�� ���
void CreateGraph_2()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex> v(6);

	vector<vector<int>> adjacent;
	// [v][v][ ][v][ ][v]
	adjacent.resize(6);
	// adjacent[0].push_back(1);
	// adjacent[0].push_back(3);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// Q) 0�� -> 3�� ����Ǿ� �ֳ���?
	bool connected = false;

	int size = adjacent[0].size();
	for (int i = 0; i < size; ++i)
	{
		int vertex = adjacent[0][i];
		if (vertex == 3)
			connected = true;
	}
}

// ���� ���
// ���̽��� ģ�� ���
void CreateGraph_3()
{
	// ����� ����� ��ķ� ����
	// [X][O][X][O][X][X]
	// [O][X][O][O][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]

	vector<bool> v(6, false);

	// adjacent[from][to] ?
	// ����� �̿��� �׷��� ǥ��
	// �޸� �Ҹ� ��������, ���� ���� ����
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;

	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;

	adjacent[3][4] = true;

	adjacent[5][4] = true;

	// Q) 0�� -> 3�� ����Ǿ� �ֳ���?
	bool connected = adjacent[0][3];

	vector<vector<int>> adjacent2 =
	{
		{ -1, 15, -1, 35, -1, -1 },
		{ 15, -1, +5, 10, -1, -1 },
		{ -1, +5, -1, -1, -1, -1 },
		{ 35, 10, -1, -1, +5, -1 },
		{ -1, -1, -1, +5, -1, +5 },
		{ -1, -1, -1, -1, +5, -1 }
	};


}

int main()
{
	vector<int> v;

}