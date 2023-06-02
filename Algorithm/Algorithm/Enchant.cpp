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
//// ENCHANT
//
//// 무기가 +1 / +2 / +3 중 하나로 강화
//// +N 무기가 뜨는 경우의 수는?
//// ex) +1 +2 +3 +4 ..... +N
//// ex) +3 +6 ... +N
//// ex) +1 +3 +4 ..... +N
//
//int N;
//int cache[100];
//
//// [+num]에서 시작해서, [+N]까지 가는 경우의 수
//int Enchant(int num)
//{
//	// 기저 사례
//	if (num > N)
//		return 0;
//	if (num == N)
//		return 1;
//
//	// 캐시
//	int& ret = cache[num];
//	if (ret != -1)
//		return ret;
//
//	// 적용
//	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);
//}
//
//int main()
//{
//	N = 9;
//
//	memset(cache, -1, sizeof(cache));
//
//	int ret = Enchant(0);
//	cout << ret << endl;
//}