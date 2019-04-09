#include <iostream>
#include <deque>
#include <set>

using namespace std;

typedef struct point
{
	int r;
	int c;
}Point;


int arr[1001][1001] = { 0, };
int resultArr[1001][1001] = { 0, };
int check[1001][1001] = { 0, };
int dir[4][2] = { {0, 1}, {0,-1},{1,0},{-1,0} };
deque<int> nodeSize;


int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	int nodeNum = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0 && check[i][j] == 0)
			{	

				deque<Point> dq;
				dq.push_back({ i, j });
				check[i][j] = nodeNum;
				int temp = 1;

				while (1)
				{
					if (dq.empty())
					{
						nodeSize.push_back(temp);
						break;
					}

					Point nowP = dq.front();
					dq.pop_front();


					int nowR = nowP.r;
					int nowC = nowP.c;

					for (int i = 0; i < 4; i++)
					{
						int nextR = nowR + dir[i][0];
						int nextC = nowC + dir[i][1];

						if (nextR >= 0 && nextC >= 0 && nextR < n && nextC < m && arr[nextR][nextC] == 0 && check[nextR][nextC] == 0)
						{
							temp++;
							check[nextR][nextC] = nodeNum;
							dq.push_back({ nextR, nextC });
						}
					}
				}


				nodeNum++;
			}

			
		}
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		printf("%d ", check[i][j]);
	//	}
	//	printf("\n");
	//}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] != 0)
			{
				set<int> s;

				//printf("i: %d j : %d\n", i, j);

				for (int k = 0; k < 4; k++)
				{
					int nextR = i + dir[k][0];
					int nextC = j + dir[k][1];
					//printf("	nextR:%d, nextC:%d\n", nextR, nextC);
					if (nextC >= 0 && nextR >= 0 && nextC < m && nextR < n && arr[nextR][nextC] == 0)
					{
						//printf("		pass\n");
						s.insert(check[nextR][nextC]);
					}
				}

				//printf("s.size: %d\n", s.size());

				for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
				{
					//printf("*iter:%d\n", *iter);
					resultArr[i][j] += nodeSize[(*iter)-1];
				}
				
				resultArr[i][j] += 1;


			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d", resultArr[i][j] % 10);
		}
		printf("\n");
		
	}
}