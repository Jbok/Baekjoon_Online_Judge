#include <iostream>
#include <deque>

using namespace std;

int arr[20][20];
int dir[4][2] = { {0,1}, {0,-1}, {1, 0}, {-1, 0} };


int comArr[2] = { 0, };

int n = 0;
int m = 0;
int max; 
int result = 0;

void Combination(int start, int end, int idx )
{
	if (idx == 2)
	{
		int r1, r2, c1, c2;
		r1 = (comArr[0] - 1) / m;
		c1 = (comArr[0] - 1) % m;

		r2 = (comArr[1] - 1) / m;
		c2 = (comArr[1] - 1) % m;

		deque<pair<int, int>> dq;

		if (arr[r1][c1] != 0 && arr[r2][c2] != 0)
		{
			return;
		}

		if (arr[r1][c1] == 0)
		{
			dq.push_back({ r1, c1 });
			arr[r1][c1] = 1;
		}

		if (arr[r2][c2] == 0)
		{
			dq.push_back({ r2, c2 });
			arr[r2][c2] = 1;
		}


			//return;


		int tresult = 0;
		int check[20][20] = { 0, };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 2 && check[i][j] == 0)
				{
					deque<pair<int, int>> dq2;
					dq2.push_back({ i,j });
					check[i][j] = 1;

					int open = 0;
					int tempResult = 1;

					while (1)
					{	
						if (dq2.empty())
						{					
							if (open == 0)
							{
								tresult += tempResult;
							}
							break;

						}
							

						pair<int, int> temp = dq2.front();
						dq2.pop_front();

						int nowR = temp.first;
						int nowC = temp.second;
						
						for (int i = 0; i < 4; i++)
						{
							int nextR = nowR + dir[i][0];
							int nextC = nowC + dir[i][1];

							if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && check[nextR][nextC] == 0)
							{
								if (arr[nextR][nextC] == 2)
								{
									check[nextR][nextC] = 1;
									tempResult++;
									dq2.push_back({ nextR, nextC });
								}
								else if (arr[nextR][nextC] == 0)
								{
									open = 1;
								}

							}

						}

					}

				}
			}
		}

		while (1)
		{
			if (dq.empty())
				break;

			pair<int, int> temp = dq.front();
			dq.pop_front();

			arr[temp.first][temp.second] = 0;
		}

		if (tresult > result)
			result = tresult;

		return;
	}
	else if (end - start < 1 - idx)
	{
		return;
	}
	else
	{
		Combination(start + 1, end, idx);

		comArr[idx] = start;
		Combination(start + 1, end, idx + 1);
	}
}


int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	/////////////


	deque<pair<int, int>> dq;

	int tresult = 0;
	int check[20][20] = { 0, };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 2 && check[i][j] == 0)
			{
				deque<pair<int, int>> dq2;
				dq2.push_back({ i,j });
				check[i][j] = 1;

				int open = 0;
				int tempResult = 1;

				while (1)
				{
					if (dq2.empty())
					{
						if (open == 0)
						{
							tresult += tempResult;
						}
						break;

					}


					pair<int, int> temp = dq2.front();
					dq2.pop_front();

					int nowR = temp.first;
					int nowC = temp.second;

					for (int i = 0; i < 4; i++)
					{
						int nextR = nowR + dir[i][0];
						int nextC = nowC + dir[i][1];

						if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && check[nextR][nextC] == 0)
						{
							if (arr[nextR][nextC] == 2)
							{
								check[nextR][nextC] = 1;
								tempResult++;
								dq2.push_back({ nextR, nextC });
							}
							else if (arr[nextR][nextC] == 0)
							{
								open = 1;
							}

						}

					}

				}

			}
		}
	}
	if (tresult > result)
		result = tresult;
	
	///////////

	int tarr[2];
	Combination(1, n*m, 0);
	
	printf("%d\n", result);
}