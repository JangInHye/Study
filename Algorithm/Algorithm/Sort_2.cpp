//#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
//#include <thread>
//
//// �� ����
//// O(NlogN)
//void HeapSort(vector<int>& v)
//{
//	priority_queue<int, vector<int>, greater<int>> pq;
//
//	// O(NlogN)
//	for (int num : v)
//		pq.push(num);
//
//	v.clear();
//
//	// O(NlogN)
//	while (pq.empty() == false)
//	{
//		v.push_back(pq.top());
//		pq.pop();
//	}
//}
//
//// ���� ����
//// ���� ���� (Divide and Conquer)
//// - ���� (Divide)		������ �� �ܼ��ϰ� �����Ѵ�.
//// - ���� (Conquer)	���ҵ� ������ �ذ�
//// - ���� (Combine)	����� �����Ͽ� ������
//// O(NlogN)
//void MergeResult(vector<int>& v, int left, int mid, int right)
//{
//	int leftIdx = left;
//	int rightIdx = mid + 1;
//
//	vector<int> temp;
//	while (leftIdx <= mid && rightIdx <= right)
//	{
//		if (v[leftIdx] <= v[rightIdx])
//		{
//			temp.push_back(v[leftIdx]);
//			leftIdx++;
//		}
//		else
//		{
//			temp.push_back(v[rightIdx]);
//			rightIdx++;
//		}
//	}
//
//	// ������ ���� ��������, ������ ������ ������ ����
//	if (leftIdx > mid)
//	{
//		while (rightIdx <= right)
//		{
//			temp.push_back(v[rightIdx]);
//			rightIdx++;
//		}
//	}
//	// �������� ���� ��������, ���� ������ ������ ����
//	else
//	{
//		while (leftIdx <= mid)
//		{
//			temp.push_back(v[leftIdx]);
//			leftIdx++;
//		}
//	}
//
//	for (int i = 0; i < temp.size(); i++)
//	{
//		v[left + i] = temp[i];
//	}
//}
//
//void MergeSort(vector<int>& v, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int mid = (left + right) / 2;
//	MergeSort(v, left, mid);
//	MergeSort(v, mid + 1, right);
//
//	MergeResult(v, left, mid, right);
//}
//
//// �� ����
//int Partition(vector<int>& v, int left, int right)
//{
//	int pivot = v[left];
//	int low = left + 1;
//	int high = right;
//
//	// ������ �� ������ ����
//	// O(N)
//	while (low <= high)
//	{
//		while (low <= right && v[low] <= pivot)
//			low++;
//		while (left + 1 <= high && pivot <= v[high])
//			high--;
//
//		if (low < high)
//			swap(v[low], v[high]);
//	}
//
//	swap(v[left], v[high]);
//
//	return high;
//}
//
//// O(N^2) < �־�
//// O(NlogN) < ���
//void QuickSort(vector<int>& v, int left, int right)
//{
//	if (left > right)
//		return;
//
//	int pivot = Partition(v, left, right);
//	QuickSort(v, left, pivot - 1);
//	QuickSort(v, pivot + 1, right);
//}
//
//int main()
//{
//	vector<int> v;
//
//	srand(time(0));
//
//	for (int i = 0; i < 50; i++)
//	{
//		int randValue = rand() % 100;
//		v.push_back(randValue);
//	}
//
//	//MergeSort(v, 0, v.size() - 1);
//	QuickSort(v, 0, v.size() - 1);
//
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << endl;
//	}
//}