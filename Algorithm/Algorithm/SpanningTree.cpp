//#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
//#include <thread>
//
//// 그래프/트리 응용
//// 최소 스패닝 트리 (Minimum Spanning Tree)
//// 그래프에 사이클이 생기면 안된다.
//
//// 크루스칼 (KRUSKAL) MST 알고리즘
//// - greedy 방법을 이용
//// - 지금 이 순간에 최적인 답을 선택하여 결과를 도출
//
//class DisjointSet
//{
//public:
//	DisjointSet(int n) : _parent(n), _rank(n, 1)
//	{
//		for (int i = 0; i < n; i++)
//			_parent[i] = i;
//	}
//
//	// 부모 찾기
//	int Find(int u)
//	{
//		if (u == _parent[u])
//			return u;
//
//		// _parent[u] = Find(_parent[u]);
//		// return _parent[u];
//
//		return _parent[u] = Find(_parent[u]);
//	}
//
//	// u와 v를 합친다. (u가 v밑으로)
//	void Merge(int u, int v)
//	{
//		u = Find(u);
//		v = Find(v);
//
//		if (u == v)
//			return;
//
//		if (_rank[u] > _rank[v])
//			swap(u, v);
//		// rank[u] <= rank[v] 보장
//
//		_parent[u] = v;
//		if (_rank[u] == _rank[v])
//			_rank[v]++;
//	}
//
//private:
//	vector<int> _parent;
//	vector<int> _rank;
//};
//
//struct Vertex
//{
//	// int data;
//};
//
//vector<Vertex> vertices;
//vector<vector<int>> adjacent;
//
//void CreateGraph()
//{
//	vertices.resize(6);
//	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
//
//	adjacent[0][1] = adjacent[1][0] = 15;
//	adjacent[0][3] = adjacent[3][0] = 35;
//	adjacent[1][2] = adjacent[2][1] = 5;
//	adjacent[1][3] = adjacent[3][1] = 10;
//	adjacent[3][4] = adjacent[4][3] = 5;
//	adjacent[3][5] = adjacent[5][3] = 10;
//	adjacent[5][4] = adjacent[4][5] = 5;
//}
//
//// u->v
//struct CostEdge
//{
//	int cost;
//	int u;
//	int v;
//
//	bool operator<(CostEdge& other)
//	{
//		return cost < other.cost;
//	}
//};
//
//int Kruskal(vector<CostEdge>& selected)
//{
//	int ret = 0;
//
//	selected.clear();
//
//	vector<CostEdge> edges;
//
//	// 간선 만들기
//	for (int u = 0; u < adjacent.size(); u++)
//	{
//		for (int v = 0; v < adjacent[u].size(); v++)
//		{
//			if (u > v)			// 간선을 두 번 만들지 않도록 하기 위함.
//				continue;
//
//			int cost = adjacent[u][v];
//			if (cost == -1)
//				continue;
//
//			edges.push_back(CostEdge{ cost, u, v });
//		}
//	}
//
//	// 코스트 순으로 정렬
//	std::sort(edges.begin(), edges.end());
//
//	DisjointSet sets(vertices.size());
//	for (CostEdge& edge : edges)
//	{
//		// 같은 그룹이면 스킵 (안 그러면 사이클이 발생한다.)
//		if (sets.Find(edge.u) == sets.Find(edge.v))
//			continue;
//
//		// 두 그룹을 합친다.
//		sets.Merge(edge.u, edge.v);
//		selected.push_back(edge);
//		ret += edge.cost;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	CreateGraph();
//
//	vector<CostEdge> selected;
//	int cost = Kruskal(selected);
//}