#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS (depth first search)
// DFS = 재귀함수 = 스택
// BFS = 

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

// 내가 방문한 목록
vector<bool> visited;

void CreateGraph()
{
	vertices.resize(6);

	// 인접 리스트
	/*adjacent = vector<vector<int>>(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };*/

	// 인접 행렬
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
	// 방문 도장
	visited[here] = true;
	cout << "Visited: " << here << endl;

	//// 인접한 길을 다 체크해서
	
	// V 정점 개수
	// E 엣지의 총 개수
	// 인접 리스트 O(V + E)
	/*
	const int size = adjacent[here].size();
	for (int i = 0; i < size; ++i)
	{
		int there = adjacent[here][i];
		
		if (visited[there] == false)
			Dfs(there);
	}
	*/

	// 인접 행렬 O(V^2)
	for (int there = 0; there < 6; ++there)
	{
		// 길은 있는지
		if (adjacent[here][there] == 0)
			continue;

		// 아직 방문하지 않은 곳에 한해서 방문
		if (visited[there] == false)
			Dfs(there);
	}

	// 인접 리스트와 인접 행렬중 뭐가 더 좋은 방법이냐?
	// - 빽빽하게 연결된 경우 - 인접 행렬
	// - 드문드문 연결된 경우 - 인접 리스트
	// 즉, 상황에 따라서 판별하여 사용
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