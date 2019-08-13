#include <iostream>
#include <algorithm>

using namespace std;

int arr[100][100] = { 0, };
int visit[100][100] = { 0, };

int arrSize[100000] = { 0, };

int dir[4][2] = { {1,0}, {-1, 0}, {0,1}, {0, -1} };

int n, m, k;

void dfs(int r, int c, int idx)
{
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + dir[i][0];
		int nextC = c + dir[i][1];

		if (nextR >= 0 && nextC >= 0 && nextR < m && nextC < n && arr[nextR][nextC] == 0 && visit[nextR][nextC] == 0)
		{
			arrSize[idx]++;
			visit[nextR][nextC] = 1;
			dfs(nextR, nextC, idx);
		}
	}
}

int main()
{

	cin >> m >> n >> k;

	for (int tc = 0; tc < k; tc++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				arr[i][j] = 1;
			}
		}
	}

	int idx = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0 && visit[i][j] == 0)
			{
				arrSize[idx]++;
				visit[i][j] = 1;
				dfs(i, j, idx);

				idx++;
			}
		}
	}

	printf("%d\n", idx);
	sort(arrSize, arrSize + idx, less<int>());

	for (int i = 0; i < idx; i++)
	{
		printf("%d ", arrSize[i]);
	}
	printf("\n");
}