#include <iostream>
#include <cstdio>

using namespace std;

int arr[50][50] = { 0, };
int check[50][50] = { 0, };
int main()
{
	int n, m;
	cin >> n >> m;
	
	int r, c, lookDir;
	cin >> r >> c >> lookDir;
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	int result = 0;

	int cnt = 2;

	int nowR = r;
	int nowC = c;
	int nowDir = lookDir;
	int checkFlag = 0;
	while (1)
	{
		
		//step.1
		if (arr[nowR][nowC] == 0 && check[nowR][nowC] == 0)
		{
			check[nowR][nowC] = cnt++ - 1;
			result++;

			/*
			printf("\n");
			printf("=====================\n");
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					printf("%2d ", arr[i][j]);
				}
				printf("\n");
			}
			printf("=====================\n");
			printf("\n");
			*/
		}
		

		

		//step.2
		int nextR = nowR;
		int nextC = nowC;
		int nextDir;

		//d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽
		if (nowDir == 0)
		{
			nextC = nowC - 1;
			nextDir = 3;
		}
		else if (nowDir == 1)
		{
			nextR = nowR - 1;
			nextDir = 0;
		}
		else if (nowDir == 2)
		{
			nextC = nowC + 1;
			nextDir = 1;
		}
		else if (nowDir == 3)
		{
			nextR = nowR + 1;
			nextDir = 2;
		}

		//2.a
		if (nextR < n && nextR >= 0 && nextC < m && nextC >= 0 && arr[nextR][nextC] == 0 && check[nextR][nextC] == 0)
		{
			nowDir = nextDir;
			nowR = nextR;
			nowC = nextC;
			checkFlag = 0;
		}
		else
		{
			nowDir = nextDir;
			checkFlag++;
		}

		//2.c
		if (checkFlag == 4)
		{
			int backR = nowR;
			int backC = nowC;

			if (nowDir == 0)
			{
				backR = nowR + 1;
			}
			else if (nowDir == 1)
			{
				backC = nowC - 1;
			}
			else if (nowDir == 2)
			{
				backR = nowR - 1;
			}
			else if (nowDir == 3)
			{
				backC = nowC + 1;
			}

			if (backR < n && backR >= 0 && backC < m && backC >= 0 && arr[backR][backC] == 0)
			{
				nowR = backR;
				nowC = backC;
				checkFlag = 0;
			}
			else
			{
				// 2.d
				break;
			}

		}
		
	}

	printf("%d\n", result);
}