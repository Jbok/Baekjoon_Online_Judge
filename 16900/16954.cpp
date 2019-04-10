#include <iostream>
#include <deque>

using namespace std;

int dir[9][2] = { {0,1}, {0,-1}, {1,0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}, {0,0} };
int arr[8][8] = { 0, };

int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char temp;
			scanf("%c", &temp);

			if (temp == '\n')
			{
				scanf("%c", &temp);
			}


			if (temp == '.')
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 1;
			}
		}
	}


	int R = 7;
	int C = 0;

	deque<pair<pair<int, int>, int>> dq;
	dq.push_back({ { R, C }, 1 });

	int flag = 0;

	while (1)
	{
		if (dq.empty())
		{
			printf("%d\n", 0);
			return 0;
		}

		pair<int, int> temp = dq.front().first;
		int cnt = dq.front().second;

		if (cnt == 8)
		{
			printf("%d\n", 1);
			return 0;
		}

		dq.pop_front();

		int nexAtrr[8][8] = { 0, };
		for (int i = 7; i >= cnt; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				nexAtrr[i][j] = arr[i-cnt][j];
			}
		}


		

		int tarr[8][8] = { 0, };
		for (int i = 7; i >= cnt-1; i--)
		{
			for (int j = 0; j < 8; j++)
			{
				tarr[i][j] = arr[i-cnt+1][j];
			}
		}


		for (int i = 0; i < 9; i++)
		{
			int nextR = temp.first + dir[i][0];
			int nextC = temp.second + dir[i][1];

			if (nextR >= 0 && nextC >= 0 && nextR < 8 && nextC < 8 && tarr[nextR][nextC] == 0)
			{
				if (nexAtrr[nextR][nextC] == 0)
				{
					dq.push_back({ {nextR, nextC}, cnt+1});
				}
			}
		}

	}
}