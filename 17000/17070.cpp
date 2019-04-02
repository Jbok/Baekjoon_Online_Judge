#include <iostream>
#include <deque>

using namespace std;

typedef struct point
{
	int r;
	int c;
}Point;

typedef struct pipe
{
	int state;	// 가로:0	세로:1	대각선:2
	Point end;
}Pipe;

int arr[16][16] = { 0, };
int result = 0;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	Pipe first = { 0, {0,1} };

	deque<Pipe> dq;
	dq.push_back(first);

	while (1)
	{
		if (dq.empty())
			break;

		Pipe now = dq.front();
		dq.pop_front();

		int nowState = now.state;

		if (now.end.r == n - 1 && now.end.c == n - 1)
		{
			result++;
		}
		else
		{
			if (nowState == 0)
			{
				for (int i = 0; i < 3; i++)
				{
					Pipe next;
					if (i == 0)
					{
						next.end = { now.end.r, now.end.c + 1 };
						next.state = i;

						if (next.end.c < n && arr[next.end.r][next.end.c] == 0)
						{
							dq.push_back(next);
						}
					}
					else if (i == 2)
					{
						next.end = { now.end.r + 1, now.end.c + 1 };
						next.state = i;

						if (next.end.r < n && next.end.c < n && arr[next.end.r][next.end.c] == 0 && arr[now.end.r + 1][now.end.c] == 0 && arr[now.end.r][now.end.c + 1] == 0)
						{
							dq.push_back(next);
						}
					}
				}
			}
			else if (nowState == 1)
			{
				for (int i = 1; i < 3; i++)
				{
					Pipe next;
					if (i == 1)
					{
						next.end = { now.end.r + 1, now.end.c };
						next.state = i;

						if (next.end.r < n && arr[next.end.r][next.end.c] == 0)
						{
							dq.push_back(next);
						}
					}
					else if (i == 2)
					{
						next.end = { now.end.r + 1, now.end.c + 1 };
						next.state = i;

						if (next.end.r < n && next.end.c < n && arr[next.end.r][next.end.c] == 0 && arr[now.end.r + 1][now.end.c] == 0 && arr[now.end.r][now.end.c + 1] == 0)
						{
							dq.push_back(next);
						}
					}
				}
			}
			else if (nowState == 2)
			{
				for (int i = 0; i < 3; i++)
				{
					Pipe next;
					if (i == 0)
					{
						next.end = { now.end.r, now.end.c + 1 };
						next.state = i;

						if (next.end.c < n && arr[next.end.r][next.end.c] == 0)
						{
							dq.push_back(next);
						}
					}
					else if (i == 1)
					{
						next.end = { now.end.r + 1, now.end.c };
						next.state = i;

						if (next.end.r < n && arr[next.end.r][next.end.c] == 0)
						{
							dq.push_back(next);
						}
					}
					else if (i == 2)
					{
						next.end = { now.end.r + 1, now.end.c + 1 };
						next.state = i;

						if (next.end.r < n && next.end.c < n && arr[next.end.r][next.end.c] == 0 && arr[now.end.r + 1][now.end.c] == 0 && arr[now.end.r][now.end.c + 1] == 0)
						{
							dq.push_back(next);
						}
					}
				}
			}
		}

	}

	printf("%d\n", result);
}