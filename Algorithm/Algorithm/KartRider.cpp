#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;
#include <thread>
#include <Windows.h>

// ���� ��ȹ�� (DP)
// KART-RIDER

// īƮ�� ������ �����ϸ� �޸��� �����ϸ�, �־��� �ð� (T) ���� �޸���.
// īƮ�� �ʱ� �⺻�ӵ� (�ʼ� 1)
// ������ �����ϰ� Ư�� �ð�(a)�� �Ǹ� �ٴڿ� �Ź� ������ ����
// īƮ�� �Ź��� �Űų� ����ġ�ų�, ������ �Ź��� �ٽ� ���� �� ����.
// �Ź��� �����Ϸ��� (b)�ð� �ʿ�, (b)�� ���� �����־�� �Ѵ�.
// �Ź��� �����ϸ� �����ð�(c)���� �Ź� �ӵ�(d)�� �޸� �� �ִ�.
// �Ź��� �ϳ��� ���� ���� ���� �ֱٿ� ������ �Ź��� �ӵ��� ����
// �Ź��� ���ų� �ٸ� �Ź߷� �ٲ� ���� �߰��ð��� ����. (���ο� �Ź��� �Ŵ� �ð��� �ҿ�ȴ�.)
// �Ź� ȿ���� ������ �ٽ� �⺻ �ӵ� (�ʼ� 1)�� �޸���.

// Q) �����Ǵ� ��� �Ź� ������ �־����� �� (T)�� ���� �� �� �ִ� �ִ� �Ÿ��� ���϶�.

struct Shoe
{
	Shoe(int a, int b, int c, int d)
	{
		time = a;
		start = a + b;
		end = start + c;
		speed = d;
	}

	int time;			// a (�Ź� ���� �ð�)
	int start;			// a + b (�Ź� ȿ�� ���� �ð�)
	int end;			// start + c (�Ź� ȿ�� ������ �ð�)
	int speed;			// d (�Ź� �ӵ�)
};

int T;
vector<Shoe> shoes;
vector<int> cache;

// input.txt
// 20						// �־��� �ð� T
// 4						// �Ź� ����
// 3 4 10 3				// �Ź� 1
// 4 1 4 2				    // �Ź� 2
// 10 2 5 5				// �Ź� 3
// 15 1 3 7				// �Ź� 4

// now�� �Ź��� �Ű� �� �� �ִ� �ִ� �Ÿ��� ��ȯ
int Solve(int now)
{
	// ���� ���
	if (now >= shoes.size())
		return 0;
	
	// ĳ�� Ȯ��
	int& ret = cache[now];
	if (ret != -1)
		return ret;

	// ����
	Shoe& shoe = shoes[now];
	// �Ź� �Ű� �̵��� �Ÿ� + �ɾ �̵��� �Ÿ�
	int dist = (shoe.end - shoe.start) * shoe.speed + (T - shoe.end) * 1;
	ret = max(ret, dist);

	// �ٸ� �Źߵ� �ϳ��� �ž��
	for (int next = now + 1; next < shoes.size(); next++)
	{
		Shoe& nextShoe = shoes[next];
		if (nextShoe.time < shoe.start)
			continue;

		// ���� �Ź߱��� �̵��Ÿ�
		int moveDist = 0;

		// ���� �Ź� ȿ���� ������ ���� ���� �Ź��� ���� ��
		if (nextShoe.time <= shoe.end)
		{
			moveDist = (nextShoe.time - shoe.start) * shoe.speed;		// �Ź� �Ű� �̵�
		}
		else
		{
			moveDist = (shoe.end - shoe.start) * shoe.speed;			// �Ź� �Ű� �̵�
			moveDist += (nextShoe.time - shoe.end) * 1;				// ������ �κ��� �ɾ �̵�
		}

		ret = max(ret, moveDist + Solve(next));
	}

	return ret;
}

int main()
{
	// �� �̵� �ð�
	T = 20;

	// �ð����� �����Ǵ� �Ź� ���
	shoes.push_back(Shoe(0, 0, T, 1));				// �⺻ �ӵ��� �Ź߷� ����
	shoes.push_back(Shoe(3, 4, 10, 3));
	shoes.push_back(Shoe(4, 1, 4, 2));
	shoes.push_back(Shoe(10, 2, 5, 5));
	shoes.push_back(Shoe(15, 1, 3, 7));

	std::sort(shoes.begin(), shoes.end(), [=](Shoe& left, Shoe& right) {return left.time < right.time; });

	// ĳ��
	cache = vector<int>(shoes.size(), -1);

	int ret = Solve(0);

	cout << ret << endl;
}