//#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
//
//// 이진 탐색 (Binary search)
//// 상황) 배열에 데이터가 정렬되어 있다
//
//// Q) 82라는 숫자가 배열에 있습니까?
//// A) 중간에 있는 값 비교해서 반절씩 후보를 없앤다.
//// [1][8][15][23][32][44][56][63][81][91]
//
//// - 정렬된 배열을 이용해서 이진 탐색 가능 (numbers[mid])
//// -- 배열은 중간 삽입/삭제가 느리다는 단점이 있다.   -> 트리로 만들자!
//// - 정렬된 연결 리스트로는 불가 (임의 접근X)
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
//		cout << "탐색 범위 : " << left << "~" << right << endl;
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
//			cout << "찾음!" << endl;
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
