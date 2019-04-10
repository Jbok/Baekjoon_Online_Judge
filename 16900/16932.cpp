#include <iostream>
#include <deque>
#include <set>


using namespace std;

int arr[1001][1001];
int check[1001][1001];
int dir[4][2] = { {0,1}, {0, -1}, {1, 0},{-1,0} };
int group[1000000] = { 0, };

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	int groupNum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int groupSize = 0;

			if (arr[i][j] == 1 && check[i][j] == 0)
			{
				groupNum++;

				deque<pair<int, int>> dq;
				dq.push_back({ i, j });

				check[i][j] = groupNum;
				groupSize++;

				while (1)
				{
					if (dq.empty())
					{
						group[groupNum] = groupSize;
						break;
					}

					int nowR = dq.front().first;
					int nowC = dq.front().second;
					dq.pop_front();

					for (int i = 0; i < 4; i++)
					{
						int nextR = nowR + dir[i][0];
						int nextC = nowC + dir[i][1];

						if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && check[nextR][nextC] == 0 && arr[nextR][nextC] == 1)
						{
							groupSize++;
							check[nextR][nextC] = groupNum;
							dq.push_back({ nextR, nextC });
						}
					}
				}
			}

		}
	}

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (arr[i][j] == 0)
			{
				set<int> s;

				for (int k = 0; k < 4; k++)
				{
					int nextR = i + dir[k][0];
					int nextC = j + dir[k][1];

					if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m)
					{
						s.insert(check[nextR][nextC]);
					}
				}

				int min = 0;

				for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
				{
					min += group[*iter];
				}

				if (min > result)
				{
					result = min;
				}
			}


		}
	}

	printf("%d\n", result+1);

}