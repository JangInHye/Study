//#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
//#include <thread>
//
//// ��ȣ ��Ÿ�� ���� (Disjoint Set)
//// -> ���Ͽ�-���ε� Union-Find
//
//// Ʈ�� ������ �̿��� ��ȣ ��Ÿ�� ������ ǥ��
//// [0] [1] [2] [3] [4] [5]
//struct Node
//{
//	Node* leader;
//};
//
//// [1]         [3]
//// [2]      [4][5]
////             [0]
//
//// �ð� ���⵵ : Ʈ���� ���̿� ����� �ð��� �ɸ�
//class NaiveDisjointSet
//{
//public:
//	NaiveDisjointSet(int n) : _parent(n)
//	{
//		for (int i = 0; i < n; i++)
//			_parent[i] = i;
//	}
//
//	// �θ� ã��
//	int Find(int u)
//	{
//		if (u == _parent[u])
//			return u;
//
//		return Find(_parent[u]);
//	}
//
//	// u�� v�� ��ģ��. (u�� v������)
//	void Merge(int u, int v)
//	{
//		u = Find(u);
//		v = Find(v);
//
//		if (u == v)
//			return;
//
//		_parent[u] = v;
//	}
//
//private:
//	vector<int> _parent;
//};
//
//// Ʈ���� �������� ���� ������ �ذ�
//// Ʈ���� ��ĥ �� �׻� ���̰� ���� Ʈ���� ���̰� ���� Ʈ�� ������ �̵�
//// Union-By-Rank ��ũ�� ���� ��ġ�� ����ȭ
//
//// �ð� ���⵵ O(Ackermann(n)) = O(1)
//class DisjointSet
//{
//public:
//	DisjointSet(int n) : _parent(n), _rank(n, 1)
//	{
//		for (int i = 0; i < n; i++)
//			_parent[i] = i;
//	}
//
//	// �θ� ã��
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
//	// u�� v�� ��ģ��. (u�� v������)
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
//		// rank[u] <= rank[v] ����
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
//int main()
//{
//	DisjointSet teams(1000);
//
//	teams.Merge(10, 1);
//	int teamid = teams.Find(1);
//	int teamid2 = teams.Find(10);
//
//	teams.Merge(3, 2);
//	int teamid3 = teams.Find(3);
//	int teamid4 = teams.Find(2);
//
//	teams.Merge(1, 3);
//	int teamid5 = teams.Find(1);
//	int teamid6 = teams.Find(3);
//
//}