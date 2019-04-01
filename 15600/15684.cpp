#include <iostream>
#include <deque>

using namespace std;

int arr[34][14] = { 0, };
int comArr[4] = { 0, };

int n, m, h;

int flag = 0;

int checkLadder(int ladderNum)
{
	int r, c;
	r = 1;
	c = ladderNum;

	while (1)
	{
		if (r == h+1)
			break;

		if (arr[r][c - 1] == 1)
		{
			c -= 1;
		}
		else if (arr[r][c] == 1)
		{
			c += 1;
		}
		
		r += 1;
	}

	return c;
}

void Combination(int start, int now, int end, int need)
{
	if (flag == 0)
	{
		if (need == now)
		{
			deque<int> dq;
			for (int i = 0; i < need; i++)
			{
				int temp = comArr[i];
				int tR = (temp - 1) / n + 1;
				int tC = (temp - 1) % n + 1;

				if (arr[tR][tC - 1] == 1 || arr[tR][tC + 1] == 1)
				{
					while (1)
					{
						if (dq.empty())
							break;

						int temp = dq.front();
						dq.pop_front();

						int tR = (temp - 1) / n + 1;
						int tC = (temp - 1) % n + 1;

						arr[tR][tC] = 0;
					}
					return;
				}

				if (arr[tR][tC] == 0)
				{
					dq.push_back(temp);
				}
				arr[tR][tC] = 1;
			}

			/*
			printf("\n");
			for (int i = 0; i <= h; i++)
			{
				for (int j = 0; j <= n; j++)
				{
					printf("%d ", arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			*/

			flag = 1;
			for (int i = 1; i <= n; i++)
			{
				if (i != checkLadder(i))
				{
					flag = 0;
					break;
				}
			}

			while (1)
			{
				if (dq.empty())
					break;

				int temp = dq.front();
				dq.pop_front();

				int tR = (temp - 1) / n + 1;
				int tC = (temp - 1) % n + 1;

				arr[tR][tC] = 0;			
			}


			return;
		}
		else if (end - start + 1 < need - now)
		{
			return;
		}
		else
		{
			Combination(start + 1, now, end, need);
			comArr[now] = start;
			Combination(start + 1, now + 1, end, need);
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &h);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		arr[a][b] = 1;
	}

	for (int i = 0; i < 4; i++)
	{
		//printf("i: %d\n", i);
		Combination(1, 0, n*h, i);
		if (flag == 1)
		{
			printf("%d\n", i);
			break;
		}
	}

	if (flag == 0)
	{
		printf("-1\n");
	}
	
}