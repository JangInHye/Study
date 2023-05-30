//#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
//#include <thread>
//
//// 버블 정렬 (Bubble Sort)
//// 앞에서부터 2개씩 비교해서 정렬한다.
//// 가장 큰 수가 맨 뒤로 가게 된다.
//void BubbleSort(vector<int>& v)
//{
//	const int n = (int)v.size();
//
//	// (N-1) + (N-2) + ... + 2 + 1
//	// 등차수열의 합 = N * (N-1) / 2
//	// O(N^2)
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < (n - 1 - i); j++)
//		{
//			if (v[j] > v[j + 1])
//			{
//				int temp = v[j];
//				v[j] = v[j + 1];
//				v[j + 1] = temp;
//			}
//		}
//	}
//}
//
//// 선택 정렬 (Selection Sort)
//// 가장 작은 수를 순서대로 정렬한다.
//void SelectionSort(vector<int>& v)
//{
//	const int n = (int)v.size();
//
//	// O(N^2)
//	for (int i = 0; i < n - 1; i++)
//	{
//		int bestIdx = i;
//
//		for (int j = i + 1; j < n; j++)
//		{
//			if (v[j] < v[bestIdx])
//				bestIdx = j;
//		}
//
//		// 교환
//		int temp = v[i];
//		v[i] = v[bestIdx];
//		v[bestIdx] = temp;
//	}
//}
//
//// 삽입 정렬 (Insertion Sort)
//// 데이터를 앞에서부터 하나씩 새로운 곳에 옮기면서 삽입해서 정렬하는 형식
//// ㄴ 앞에서부터 하나씩 떼어서 앞의 인덱스와 비교해서 자리 바꾸기
//void InsertionSort(vector<int>& v)
//{
//	const int n = (int)v.size();
//
//	// O(N^2)
//	for (int i = 1; i < n; i++)
//	{
//		int insertData = v[i];
//		int j;
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (insertData < v[j])
//				v[j + 1] = v[j];
//			else
//				break;
//		}
//
//		v[j + 1] = insertData;
//	}
//}
//
//int main()
//{
//	vector<int> v{ 1, 5, 3, 4, 2 };
//
//	//BubbleSort(v);
//	//SelectionSort(v);
//	InsertionSort(v);
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << "[" << v[i] << "] ";
//	}
//}