//#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
//
//// ���� Ž�� (Binary search)
//// ��Ȳ) �迭�� �����Ͱ� ���ĵǾ� �ִ�
//
//// Q) 82��� ���ڰ� �迭�� �ֽ��ϱ�?
//// A) �߰��� �ִ� �� ���ؼ� ������ �ĺ��� ���ش�.
//// [1][8][15][23][32][44][56][63][81][91]
//
//// - ���ĵ� �迭�� �̿��ؼ� ���� Ž�� ���� (numbers[mid])
//// -- �迭�� �߰� ����/������ �����ٴ� ������ �ִ�.   -> Ʈ���� ������!
//// - ���ĵ� ���� ����Ʈ�δ� �Ұ� (���� ����X)
//vector<int> numbers;
//
//// O(logN)
//void BinarySearch(int N)
//{
//	int left = 0;
//	int right = (int)numbers.size() - 1;
//
//	while (left <= right)
//	{
//		cout << "Ž�� ���� : " << left << "~" << right << endl;
//
//		int mid = (left + right) / 2;
//
//		if (N < numbers[mid])
//		{
//			cout << N << " < " << numbers[mid] << endl;
//			right = mid - 1;
//		}
//		else if (N > numbers[mid])
//		{
//			cout << N << " > " << numbers[mid] << endl;
//			left = mid + 1;
//		}
//		else
//		{
//			cout << "ã��!" << endl;
//			break;
//		}
//	}
//}
//
//int main()
//{
//	numbers = vector<int>{ 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
//	BinarySearch(82);
//}
