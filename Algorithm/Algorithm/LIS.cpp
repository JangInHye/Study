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
//// LIS (Longest Increasing Sequence)
//
//// Seq : 1 9 2 5 7
//// �κ� ���� : �Ϻ�(0�� �̻�) ���ڸ� ����� ���� ����
//// ������ �����Ǿ�� �Ѵ�.
//// ex) 1 2 5
//// ex) 1 9 5 7
//// �� ���� �κ� ����
//// ���� ��� �����Ѵ�.
//// ex) 1 2 5 
//
//// LIS : ���� �� [�� ���� �κ� ����]�� ����
//// 1 2 5 7 = ���� 4
//
//int cache[100];
//vector<int> seq;
//
//int LIS(int pos)
//{
//	// ���� ����
//	//if (pos == seq.size() - 1)
//	//	return 1;
//
//	// ĳ�� Ȯ��
//	int& ret = cache[pos];
//	if (ret != -1) return ret;
//
//	// �� ���ϱ�
//	// Seq : 1 9 2 5 7
//	// 1 9 = 2
//	// 1 2 5 7 = 4
//	// 1 5 7 = 3        LIS(0) -> 1 + LIS(3) -> 1 + LIS(4)
//	// 1 7 = 2          LIS(0) -> 1 + LIS(4)
//
//	// LIS(0) = LIS(1) + 1
//	// LIS(1) = 1
//
//	// �ּ� seq[pos]�� ������ 1���� ����
//	ret = 1;
//
//	for (int next = pos + 1; next < seq.size(); next++)
//		if (seq[pos] < seq[next])
//			ret = max(ret, 1 + LIS(next));
//
//	return ret;
//}
//
//int main()
//{
//	::memset(cache, -1, sizeof(cache));
//	seq = vector<int>{ 1, 9, 2, 5, 7 };
//
//	int ret = 0;
//	for (int pos = 0; pos < seq.size(); pos++)
//		ret = max(ret, LIS(pos));
//}