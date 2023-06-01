//#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
//#include <thread>
//#include <Windows.h>
//
//// 동적 계획법 (DP)
//// Dynamic Programming
//// 문제를 보다 작은 문제로 나누어서 해결하는 방법
//
//// 메모이제이션 (memoization)
//int cache[50][50];
//
//int combination(int n, int r)
//{
//	// 기저 사례
//	if (r == 0 || n == r) return 1;
//
//	// 이미 답을 구한 적이 있으면 바로 반환
//	int& ret = cache[n][r];
//	if (ret != -1) return ret;
//
//	// 답을 모른다면 답을 구해서 캐시에 저장
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