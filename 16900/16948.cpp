#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
	int r;
	int c;
}Point;

int dir[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2,1} };
int check[201][201] = { 0, };

int main()
{
	int n;
	cin >> n;

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	deque<pair<Point, int>> dq;
	dq.push_back({ {r1, c1}, 0 });
	check[r1][c1] = 1;

	while (1)
	{
		if (dq.empty())
		{
			printf("-1\n");
			break;
		}

		Point nowP = dq.front().first;
		int nowCnt = dq.front().second;
		dq.pop_front();

		if (nowP.r == r2 && nowP.c == c2)
		{
			printf("%d\n", nowCnt);
			break;
		}

		for (int i = 0; i < 6; i++)
		{
			int nextR = nowP.r + dir[i][0];
			int nextC = nowP.c + dir[i][1];

			if (nextR >= 0 && nextR <= 200 && nextC >= 0 && nextC <= 200 && check[nextR][nextC] == 0)
			{
				check[nextR][nextC] = 1;
				dq.push_back({ {nextR, nextC}, nowCnt + 1 });
			}
			else
			{

			}
		}

	}
}