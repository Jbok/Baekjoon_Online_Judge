#include <iostream>
#include <deque>

using namespace std;

int arr[50][50] = { 0, };
int visit[50][50] = { 0, };
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int m, n, k;


void dfs(int r, int c)
{
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + dir[i][0];
		int nextC = c + dir[i][1];

		if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && arr[nextR][nextC] == 1 && visit[nextR][nextC] == 0)
		{
			visit[nextR][nextC] = 1;
			dfs(nextR, nextC);
		}
	}

}

int main()
{
	int t;
	cin >> t;

	int cnt = 0;
	while (1)
	{
		if (cnt == t)
		{
			break;
		}


		cin >> m >> n >> k;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				visit[i][j] = 0;
				arr[i][j] = 0;
			}
		}

		

		
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}


		int result = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && visit[i][j] == 0)
				{
					result++;
					dfs(i, j);
				}
			}
		}


		printf("%d\n", result);

		cnt++;
	}
}