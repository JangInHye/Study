//#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
//#include <thread>
//
//// map : Red-Black Tree					=> C#�� dictionary�ʹ� �ٸ���.
//// - �߰�/Ž��/���� O(logN)
//
//// hash_map (unordered_map)			=> C#������ dictionary
//// - �߰�/Ž��/���� O(1)
//// �޸� ���ظ� ������ �ӵ��� ������.
//
//// '�ؽ�'		'���̺�'
//// O(1)
//void TestTable()
//{
//	struct User
//	{
//		int userId = 0;
//		string username;
//	};
//
//	vector<User> users;
//	users.resize(1000);
//
//	/// 777�� ���� ���� ����
//	users[777] = User{ 777, "Name" };
//
//	// ���� �̸� ���
//	string name = users[777].username;
//	cout << name << endl;
//
//	// ���̺�
//	// Ű�� �˸� �����͸� �ܹ��� ã�� �� �ִ�.
//	// �޸𸮿��� �Ѱ谡 �ִ�.
//}
//
//// ����
//// hash�� �����ϸ� ������ ���� �ٸ� ������ ����Ǿ� ����
//// �Ϲ������̱� ������ �ؽð����� ������ ���� �� ���� ����.
//void TestHash()
//{
//	struct User
//	{
//		int userId = 0;
//		string username;
//	};
//
//	vector<User> users;
//	users.resize(1000);
//
//	const int userId = 123456789;
//	int key = (userId % 1000);		// hash < ������ȣ
//
//	/// 123456789�� ���� ���� ����
//	users[key] = User{ userId, "Name" };
//
//	// ���� �̸� ���
//	User& user = users[key];
//	if (user.userId == userId)
//	{
//		string name = user.username;
//		cout << name << endl;
//	}
//
//	// �浹 ����
//	// Ű���� ������ ��Ȳ�� �߻��� �� �ִ�.
//	// �浹�� �߻��� �ڸ��� ����ؼ� �ٸ� ���ڸ��� ã�´�.
//	// - ���� ����� (linear probing)
//	// hash(key) +1 -> hash(key) +2 ...
//	// - ���� ����� (quadratic probing)
//	// hash(key) +1^2 -> hash(key) +2^2
//	// - etc
//}
//
//// ü�̴�
//// ������ Ű���̾ ���� ���� �����ؼ� ���
//// O(1)
//void TestHashTableChaining()
//{
//	struct User
//	{
//		int userId = 0;
//		string username;
//	};
//
//	vector<vector<User>> users;
//	users.reserve(1000);
//
//	const int userId = 123456789;
//	int key = (userId % 1000);		// hash < ������ȣ
//
//	/// 123456789�� ���� ���� ����
//	users[key].push_back(User{ userId, "Name" });
//	users[789].push_back(User{ 789, "Name222" });
//
//	// ���� �̸� ���
//	vector<User>& bucket = users[key];
//	for (User& user : bucket)
//	{
//		if (user.userId == userId)
//		{
//			string name = user.username;
//			cout << name << endl;
//		}
//	}
//}
//
//int main()
//{
//	//TestTable();
//	TestHash();
//}