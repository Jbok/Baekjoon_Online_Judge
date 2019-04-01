#include <iostream>
#include <deque>
#include <math.h>

using namespace std;

int arr[52][52] = { 0, };
int dir[4][2] = { { 0, 1}, {0, -1}, {-1, 0}, {1, 0} };

int main()
{
	int n, L, R;
	cin >> n >> L >> R;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	int cnt = 0;
	while (1)
	{
		int uniNum = 0;

		deque<pair<int, int>> udq[3000];
		pair<int, int> udqArr[3000] = { { 0, 0 }, };
		int uniArr[51][51] = { 0, };
		int checkArr[51][51] = { 0, };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (checkArr[i][j] == 0)
				{
					deque<pair<int, int>> dq;

					checkArr[i][j] = 1;
					dq.push_back({ i, j });

					while (1)
					{
						if (dq.empty())
						{
							break;
						}
						else
						{
							pair<int, int> pTemp = dq.front();
							dq.pop_front();

							int nowR = pTemp.first;
							int nowC = pTemp.second;

							udqArr[uniNum].first++;
							udqArr[uniNum].second += arr[nowR][nowC];
							udq[uniNum].push_back({ nowR, nowC });

							for (int k = 0; k < 4; k++)
							{
								int nextR = pTemp.first + dir[k][0];
								int nextC = pTemp.second + dir[k][1];

								if (nextR >= 0 && nextC >= 0 && nextR < n && nextC < n && checkArr[nextR][nextC] == 0 && (abs(arr[nowR][nowC] - arr[nextR][nextC]) >= L && abs(arr[nowR][nowC] - arr[nextR][nextC]) <= R))
								{
									dq.push_back({ nextR, nextC });
									checkArr[nextR][nextC] = 1;
								}
							}
						}
					}


					uniNum++;
				}

			}
		}

		if (uniNum == n * n)
		{
			printf("%d\n", cnt);
			break;
		}

		for (int i = 0; i < uniNum; i++)
		{
			int peopleNum = udqArr[i].second / udqArr[i].first;

			while (1)
			{
				if (udq[i].empty())
				{
					break;
				}
				else
				{
					int nowR = udq[i].front().first;
					int nowC = udq[i].front().second;
					udq[i].pop_front();

					arr[nowR][nowC] = peopleNum;
				}
			}
		}

		cnt++;
	}

	
	

}