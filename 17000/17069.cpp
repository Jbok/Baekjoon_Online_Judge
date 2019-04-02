#include <iostream>

using namespace std;

typedef struct pipe
{
	long long state[3];	//가로:0		세로:1	대각선:2	
}Pipe;

int arr[32][32] = { 0, };
Pipe dp[32][32] = { 0, };
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = { 0, 0, 0 };
	dp[0][1] = { 1, 0, 0 };

	for (int i = 1; i < n; i++)
	{
		if (arr[0][i] == 0)
		{
			dp[0][i] = { 1, 0, 0 };
		}
		else
		{
			break;
		}
	}



	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				if (k == 0)
				{
					if (arr[i][j] != 1)
					{
						dp[i][j].state[0] += dp[i][j - 1].state[0];
					}
				}
				else if (k == 1)
				{
					if (arr[i][j] != 1 && arr[i - 1][j] != 1 && arr[i][j - 1] != 1)
					{
						dp[i][j].state[2] += dp[i - 1][j - 1].state[0];
					}
				}
				else if (k == 2)
				{
					if (arr[i][j] != 1)
					{
						dp[i][j].state[1] += dp[i - 1][j].state[1];
					}
				}
				else if (k == 3)
				{
					if (arr[i][j] != 1 && arr[i - 1][j] != 1 && arr[i][j - 1] != 1)
					{
						dp[i][j].state[2] += dp[i - 1][j - 1].state[1];
					}
				}
				else if (k == 4)
				{
					if (arr[i][j] != 1)
					{
						dp[i][j].state[0] += dp[i][j - 1].state[2];
					}
				}
				else if (k == 5)
				{
					if (arr[i][j] != 1)
					{
						dp[i][j].state[1] += dp[i - 1][j].state[2];
					}
				}
				else if (k == 6)
				{
					if (arr[i][j] != 1 && arr[i - 1][j] != 1 && arr[i][j - 1] != 1)
					{
						dp[i][j].state[2] += dp[i - 1][j - 1].state[2];
					}
				}
			}
		}
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("{%lld %lld %lld} ", dp[i][j].state[0], dp[i][j].state[1], dp[i][j].state[2]);
		}
		printf("\n");
	}*/


	printf("%lld\n", dp[n - 1][n - 1].state[0] + dp[n - 1][n - 1].state[1] + dp[n - 1][n - 1].state[2]);
}