#include <iostream>

using namespace std;

typedef struct node
{
	int r;
	int c;
	int kind;
}point;

int n, m;

int cTotal = 0;


int board[8][8];

void Up(int r, int c, int arr[8][8])
{
	if (r-1 >= 0)
	{
		if (arr[r - 1][c] != 6)
		{
			arr[r - 1][c] = 7;
			Up(r - 1, c, arr);
		}
	}
}

void Down(int r, int c, int arr[8][8])
{
	if (r + 1 < n)
	{
		if (arr[r + 1][c] != 6)
		{
			arr[r + 1][c] = 7;
			Down(r + 1, c, arr);
		}
	}
}

void Right(int r, int c, int arr[8][8])
{
	if (c + 1 < m)
	{
		if (arr[r][c + 1] != 6)
		{
			arr[r][c + 1] = 7;
			Right(r, c+1, arr);
		}
	}
}

void Left(int r, int c, int arr[8][8])
{
	if (c - 1 >= 0)
	{
		if (arr[r][c - 1] != 6)
		{
			arr[r][c - 1] = 7;
			Left(r, c - 1, arr);
		}
	}
}

point camera[8] = { 0, };

void Find(int arr[8][8], int *min, int cNum)
{
	if (cNum == cTotal)
	{
		int result = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 0)
					result++;
			}
		}

		if (*min > result)
		{
			*min = result;
		}
		return;
	}
	else
	{
		int tarr[8][8];

		for (int i = 0; i < 4; i++)
		{
			for (int ii = 0; ii < n; ii++)
			{
				for (int j = 0; j < m; j++)
				{
					tarr[ii][j] = arr[ii][j];
				}
			}

			int nR = camera[cNum].r;
			int nC = camera[cNum].c;
			int nK = camera[cNum].kind;

			if (nK == 1)
			{
				if (i == 0)
				{
					Up(nR, nC, tarr);
				}
				else if (i == 1)
				{
					Down(nR, nC, tarr);
				}
				else if (i == 2)
				{
					Right(nR, nC, tarr);
				}
				else if (i == 3)
				{
					Left(nR, nC, tarr);
				}
			}
			else if (nK == 2)
			{
				if (i == 0)
				{
					Up(nR, nC, tarr);
					Down(nR, nC, tarr);
				}
				else if (i == 1)
				{
					Right(nR, nC, tarr);
					Left(nR, nC, tarr);
				}
				else
				{
					break;
				}

			}
			else if (nK == 3)
			{
				if (i == 0)
				{
					Up(nR, nC, tarr);
					Right(nR, nC, tarr);
				}
				else if (i == 1)
				{
					Right(nR, nC, tarr);
					Down(nR, nC, tarr);
				}
				else if (i == 2)
				{
					Left(nR, nC, tarr);
					Down(nR, nC, tarr);
				}
				else if (i == 3)
				{
					Left(nR, nC, tarr);
					Up(nR, nC, tarr);
				}
			}
			else if (nK == 4)
			{
				if (i == 0)
				{
					Up(nR, nC, tarr);
					Right(nR, nC, tarr);
					Left(nR, nC, tarr);
				}
				else if (i == 1)
				{
					Up(nR, nC, tarr);
					Right(nR, nC, tarr);
					Down(nR, nC, tarr);
				}
				else if (i == 2)
				{
					Left(nR, nC, tarr);
					Right(nR, nC, tarr);
					Down(nR, nC, tarr);
				}
				else if (i == 3)
				{
					Left(nR, nC, tarr);
					Up(nR, nC, tarr);
					Down(nR, nC, tarr);
				}
			}
			else if (nK == 5)
			{
				if (i == 0)
				{
					Left(nR, nC, tarr);
					Up(nR, nC, tarr);
					Down(nR, nC, tarr);
					Right(nR, nC, tarr);
				}
				else
				{
					break;
				}
			}

			Find(tarr, min, cNum+1);
		}
	}
}

int main()
{
	cin >> n >> m;

	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			
			if (board[i][j] != 0 && board[i][j] != 6)
			{
				camera[cTotal++] = { i,j,board[i][j] };
			}
		}
	}


	int resultMin = 64;
	int *resultMinPtr = &resultMin;

	Find(board, resultMinPtr, 0);

	printf("%d\n", resultMin);

}