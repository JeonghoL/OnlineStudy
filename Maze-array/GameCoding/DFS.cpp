#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS (depth first search)
// DFS = ����Լ� = ����
// BFS = 

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

// ���� �湮�� ���
vector<bool> visited;

void CreateGraph()
{
	vertices.resize(6);

	// ���� ����Ʈ
	/*adjacent = vector<vector<int>>(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };*/

	// ���� ���
	adjacent = vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0}
	};
}

void Dfs(int here)
{
	// �湮 ����
	visited[here] = true;
	cout << "Visited: " << here << endl;

	//// ������ ���� �� üũ�ؼ�
	
	// V ���� ����
	// E ������ �� ����
	// ���� ����Ʈ O(V + E)
	/*
	const int size = adjacent[here].size();
	for (int i = 0; i < size; ++i)
	{
		int there = adjacent[here][i];
		
		if (visited[there] == false)
			Dfs(there);
	}
	*/

	// ���� ��� O(V^2)
	for (int there = 0; there < 6; ++there)
	{
		// ���� �ִ���
		if (adjacent[here][there] == 0)
			continue;

		// ���� �湮���� ���� ���� ���ؼ� �湮
		if (visited[there] == false)
			Dfs(there);
	}

	// ���� ����Ʈ�� ���� ����� ���� �� ���� ����̳�?
	// - �����ϰ� ����� ��� - ���� ���
	// - �幮�幮 ����� ��� - ���� ����Ʈ
	// ��, ��Ȳ�� ���� �Ǻ��Ͽ� ���
}

void DfsAll()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; ++i)
	{
		if (visited[i] == false)
		{
			Dfs(i);
		}
	}
}

int main()
{
	CreateGraph();

	DfsAll();
}