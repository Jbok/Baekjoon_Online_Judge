#include <iostream>
#include <deque>

using namespace std;

typedef struct point
{
	int z;
	int r;
	int c;
	int cnt = 0;
}Point;

int arr[5][5][5];
int pArr[5] = { 0, 1, 2, 3, 4 };
int dir[6][3] = { {0, 0, 1}, {0 ,0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0 , 0}, {-1, 0, 0} };

int result = 1000000;

void Rotatoin(int arr[5][5])
{
	int temp1 = arr[0][0];
	int temp2 = arr[0][1];
	int temp3 = arr[0][2];
	int temp4 = arr[0][3];
	int temp5 = arr[0][4];

	arr[0][0] = arr[4][0];
	arr[0][1] = arr[3][0];
	arr[0][2] = arr[2][0];
	arr[0][3] = arr[1][0];
	arr[0][4] = temp1;

	int ttemp2 = arr[4][0];
	arr[4][0] = arr[4][4];
	arr[3][0] = arr[4][3];
	arr[2][0] = arr[4][2];
	arr[1][0] = arr[4][1];
	arr[0][0] = ttemp2;

	int ttemp1 = arr[4][4];
	arr[4][4] = arr[0][4];
	arr[4][3] = arr[1][4];
	arr[4][2] = arr[2][4];
	arr[4][1] = arr[3][4];
	arr[4][0] = ttemp1;

	arr[0][4] = temp1;
	arr[1][4] = temp2;
	arr[2][4] = temp3;
	arr[3][4] = temp4;
	arr[4][4] = temp5;


	int temp6 = arr[1][1];
	int temp7 = arr[1][2];
	int temp8 = arr[1][3];

	arr[1][1] = arr[3][1];
	arr[1][2] = arr[2][1];
	arr[1][3] = temp6;

	int ttemp6 = arr[3][1];
	arr[3][1] = arr[3][3];
	arr[2][1] = arr[3][2];
	arr[1][1] = ttemp6;

	int ttemp7 = arr[3][3];
	arr[3][3] = arr[1][3];
	arr[3][2] = arr[2][3];
	arr[3][1] = ttemp7;

	arr[1][3] = temp6;
	arr[2][3] = temp7;
	arr[3][3] = temp8;
}

void permutation(int start, int end, int now)
{
	if (now == end)
	{
		//for (int i = 0; i < 5; i++)
		//{
		//	printf("%d ", pArr[i]);
		//	

		//}
		//printf("\n");

		int tempArr[5][5][5];
		for (int k = 0; k < 5; k++)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					tempArr[k][i][j] = arr[pArr[k]][i][j];
					//printf("%d ", tempArr[k][i][j]);
				}
				//printf("\n");
			}
			//printf("\n");
		}

		//printf("\n"); printf("\n"); printf("\n");
		

		for (int i = 0; i < 4; i++)
		{
			Rotatoin(tempArr[0]);
			for (int j = 0; j < 4; j++)
			{
				Rotatoin(tempArr[1]);
				for (int k = 0; k < 4; k++)
				{
					Rotatoin(tempArr[2]);
					for (int kk = 0; kk < 4; kk++)
					{
						Rotatoin(tempArr[3]);
						for (int kkk = 0; kkk < 4; kkk++)
						{
							Rotatoin(tempArr[4]);
							int sR, sC, sZ;
							int eR, eC, eZ;

							for (int ii = 0; ii < 1; ii++)
							{
								
								if (ii == 0)
								{
									sZ = 0;
									sR = 0;
									sC = 0;

									eZ = 4;
									eR = 4;
									eC = 4;
								}
								else if (ii == 1)
								{
									eZ = 0;
									eR = 0;
									eC = 0;

									sZ = 4;
									sR = 4;
									sC = 4;
								}
								else if (ii == 2)
								{
									sZ = 0;
									sR = 4;
									sC = 0;

									eZ = 4;
									eR = 0;
									eC = 4;
								}
								else if (ii == 3)
								{
									eZ = 0;
									eR = 4;
									eC = 0;

									sZ = 4;
									sR = 0;
									sC = 4;
								}
								else if (ii == 4)
								{
									sZ = 0;
									sR = 4;
									sC = 4;

									eZ = 4;
									eR = 0;
									eC = 0;
								}
								else if (ii == 5)
								{
									eZ = 0;
									eR = 4;
									eC = 4;

									sZ = 4;
									sR = 0;
									sC = 0;
								}
								else if (ii == 6)
								{
									sZ = 0;
									sR = 0;
									sC = 4;

									eZ = 4;
									eR = 4;
									eC = 0;
								}
								else if (ii == 7)
								{
									eZ = 0;
									eR = 0;
									eC = 4;

									sZ = 4;
									sR = 4;
									sC = 0;
								}


								if (tempArr[sZ][sR][sC] == 1)
								{
									deque<Point> dq;
									dq.push_back({ sZ, sR, sC, 0 });
									int check[5][5][5] = { 0, };
									check[sZ][sR][sC] = 1;

									while (1)
									{
										if (dq.empty())
											break;

										Point now = dq.front();
										dq.pop_front();

										if (now.r == eR && now.c == eC && now.z == eZ)
										{
											if (result > now.cnt)
											{
												result = now.cnt;
											}
											break;
										}

										for (int td = 0; td < 6; td++)
										{
											int nextR = now.r + dir[td][0];
											int nextC = now.c + dir[td][1];
											int nextZ = now.z + dir[td][2];

											if (nextR >= 0 && nextR < 5 && nextC >= 0 && nextC < 5 && nextZ >= 0 && nextZ < 5 && check[nextZ][nextR][nextC] == 0 && tempArr[nextZ][nextR][nextC] == 1)
											{
												check[nextZ][nextR][nextC] = 1;
												dq.push_back({ nextZ, nextR, nextC, now.cnt + 1 });
											}
										}
									}
								}


							}

							


						}
					}
				}
			}
		}
		


		return;
	}
	else
	{
		for (int i = now; i < end; i++)
		{
			int temp = pArr[now];
			pArr[now] = pArr[i];
			pArr[i] = temp;

			permutation(start, end, now + 1);

			temp = pArr[now];
			pArr[now] = pArr[i];
			pArr[i] = temp;
		}
	}
}



int main()
{
	for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				scanf("%d", &arr[k][i][j]);
			}
		}
	}

	permutation(0, 5, 0);
	if (result == 1000000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", result);
	}
	


	
}