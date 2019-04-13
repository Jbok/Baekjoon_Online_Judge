#include <iostream>
#include <deque>

using namespace std;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

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


		int m, n, k;
		cin >> m >> n >> k;

		int arr[50][50] = { 0, };
		int visit[50][50] = { 0, };
		
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}

		/*
		printf("\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		int result = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && visit[i][j] == 0)
				{
					//printf("i:%d j:%d\n", i, j);
					result++;
					deque<pair<int, int>> dq;
					dq.push_back({ i,j });
					
					visit[i][j] = 1;

					while (1)
					{
						if (dq.empty())
						{
							break;
						}

						pair<int, int> now = dq.front();
						dq.pop_front();

						for (int i = 0; i < 4; i++)
						{
							int nextR = now.first + dir[i][0];
							int nextC = now.second + dir[i][1];

							if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && visit[nextR][nextC] == 0 && arr[nextR][nextC])
							{
								//printf("	nextR:%d nextC:%d\n", nextR, nextC);
								visit[nextR][nextC] = 1;
								dq.push_back({ nextR, nextC });
							}
						}

					}

				}
			}
		}

		printf("%d\n", result);

		cnt++;
	}
}