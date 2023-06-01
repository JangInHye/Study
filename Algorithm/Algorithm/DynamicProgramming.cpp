//#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
//#include <thread>
//#include <Windows.h>
//
//// ���� ��ȹ�� (DP)
//// Dynamic Programming
//// ������ ���� ���� ������ ����� �ذ��ϴ� ���
//
//// �޸������̼� (memoization)
//int cache[50][50];
//
//int combination(int n, int r)
//{
//	// ���� ���
//	if (r == 0 || n == r) return 1;
//
//	// �̹� ���� ���� ���� ������ �ٷ� ��ȯ
//	int& ret = cache[n][r];
//	if (ret != -1) return ret;
//
//	// ���� �𸥴ٸ� ���� ���ؼ� ĳ�ÿ� ����
//	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
//}
//
//int main()
//{
//	::memset(cache, -1, sizeof(cache));
//
//	__int64 start = GetTickCount64();
//	int lotto = combination(45, 6);
//	__int64 end = GetTickCount64();
//
//	cout << end - start << "ms" << endl;
//}