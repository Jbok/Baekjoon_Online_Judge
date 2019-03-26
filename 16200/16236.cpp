#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
	int r;
	int c;
	int size;
	int cnt;
	int resultCnt;
	int tempsize;
}point;

int dir[4][2] = { { -1, 0}, {0,-1},{0, 1}, {1, 0} };

int main()
{
	int result = 0;

	int n;
	cin >> n;

	int arr[20][20] = { 0, };

	point shark;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			
			if (arr[i][j] == 9)
			{
				shark = { i, j, 2, 0, 0, 0 };
			}
		}
	}

	


	int inFlag = 1;
	while (1)
	{
		if (inFlag == 0)
			break;

		deque<point> dq;
		dq.push_back(shark);

		int check[20][20] = { 0, };
		check[shark.r][shark.c] = 1;
		arr[shark.r][shark.c] = 0;
		
		int tempCnt = 10000;

		while (1)
		{
			if (dq.empty())
			{
				break;
			}


			point now = dq.front();
			dq.pop_front();

			for (int i = 0; i < 4; i++)
			{

				int nextR = now.r + dir[i][0];
				int nextC = now.c + dir[i][1];

				if (nextR >= 0 && nextC >= 0 && nextR < n && nextC < n && check[nextR][nextC] == 0 && arr[nextR][nextC] <= now.size)
				{
					check[nextR][nextC] = 1;

					if (arr[nextR][nextC] == now.size)
					{

					}
					else if (arr[nextR][nextC] == 0)
					{

					}
					else
					{
						
						if (tempCnt == 10000)
						{
							tempCnt = now.resultCnt;


							int temps = arr[nextR][nextC];
							arr[nextR][nextC] = 9;
							now.cnt++;



							if (now.size == now.cnt)
							{
								now.size++;
								now.cnt = 0;
							}

							result += (now.resultCnt + 1);

							shark = { nextR, nextC, now.size, now.cnt, 0, temps };

							break;
						}
						else if (tempCnt < now.resultCnt)
						{						
							break;
						}
						else
						{
							int tempR = shark.r;
							int tempC = shark.c;

							if (tempR < nextR)
							{
								break;
							}
							else if(tempR > nextR)
							{
								int temps = arr[nextR][nextC];
								arr[tempR][tempC] = shark.tempsize;
								arr[nextR][nextC] = 9;

								shark = shark = { nextR, nextC, shark.size, shark.cnt, 0, temps };
							}
							else if (tempR == nextR && tempC > nextC)
							{
								int temps = arr[nextR][nextC];
								arr[tempR][tempC] = shark.tempsize;
								arr[nextR][nextC] = 9;

								shark = shark = { nextR, nextC, now.size, now.cnt, 0, temps };
							}
						}


					}

					dq.push_back({ nextR, nextC, now.size, now.cnt, now.resultCnt+1 });
				}
			}

		}


		inFlag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 9)
				{
					inFlag = 1;
				}
			}
		}

		/*
		printf("\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		printf("size: %d cnt:%d\n", shark.size, shark.cnt);
		printf("result:%d\n", result);
		*/
	}
	
	printf("%d\n", result);
}