//#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
//#include <thread>
//
//// map : Red-Black Tree					=> C#의 dictionary와는 다르다.
//// - 추가/탐색/삭제 O(logN)
//
//// hash_map (unordered_map)			=> C#에서는 dictionary
//// - 추가/탐색/삭제 O(1)
//// 메모리 손해를 보지만 속도가 빠르다.
//
//// '해시'		'테이블'
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
//	/// 777번 유저 정보 세팅
//	users[777] = User{ 777, "Name" };
//
//	// 유저 이름 출력
//	string name = users[777].username;
//	cout << name << endl;
//
//	// 테이블
//	// 키를 알면 데이터를 단번에 찾을 수 있다.
//	// 메모리에는 한계가 있다.
//}
//
//// 보안
//// hash를 적용하면 기존의 값이 다른 값으로 변경되어 저장
//// 일방통행이기 때문에 해시값에서 기존의 값을 알 수는 없다.
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
//	int key = (userId % 1000);		// hash < 고유번호
//
//	/// 123456789번 유저 정보 세팅
//	users[key] = User{ userId, "Name" };
//
//	// 유저 이름 출력
//	User& user = users[key];
//	if (user.userId == userId)
//	{
//		string name = user.username;
//		cout << name << endl;
//	}
//
//	// 충돌 문제
//	// 키값이 동일한 상황이 발생할 수 있다.
//	// 충돌이 발생한 자리를 대신해서 다른 빈자리를 찾는다.
//	// - 선형 조사법 (linear probing)
//	// hash(key) +1 -> hash(key) +2 ...
//	// - 이차 조사법 (quadratic probing)
//	// hash(key) +1^2 -> hash(key) +2^2
//	// - etc
//}
//
//// 체이닝
//// 동일한 키값이어도 같은 곳에 연결해서 사용
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
//	int key = (userId % 1000);		// hash < 고유번호
//
//	/// 123456789번 유저 정보 세팅
//	users[key].push_back(User{ userId, "Name" });
//	users[789].push_back(User{ 789, "Name222" });
//
//	// 유저 이름 출력
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