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
//// ENCHANT
//
//// ���Ⱑ +1 / +2 / +3 �� �ϳ��� ��ȭ
//// +N ���Ⱑ �ߴ� ����� ����?
//// ex) +1 +2 +3 +4 ..... +N
//// ex) +3 +6 ... +N
//// ex) +1 +3 +4 ..... +N
//
//int N;
//int cache[100];
//
//// [+num]���� �����ؼ�, [+N]���� ���� ����� ��
//int Enchant(int num)
//{
//	// ���� ���
//	if (num > N)
//		return 0;
//	if (num == N)
//		return 1;
//
//	// ĳ��
//	int& ret = cache[num];
//	if (ret != -1)
//		return ret;
//
//	// ����
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