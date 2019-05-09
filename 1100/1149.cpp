#include <iostream>
#include <cstdio>
#include <algorithm>

#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;

int color[1001][3] = { 0, };
int dp[1001][3] = { 0, };

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &color[i][j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		dp[0][i] = color[0][i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == RED)
			{
				dp[i][j] = min(dp[i-1][GREEN], dp[i-1][BLUE]) + color[i][RED];
			}
			else if (j == GREEN)
			{
				dp[i][j] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + color[i][GREEN];
			}
			else if (j == BLUE)
			{
				dp[i][j] = min(dp[i - 1][GREEN], dp[i - 1][RED]) + color[i][BLUE];
			}
		}
	}


	int minResult = min(dp[n - 1][0], dp[n - 1][1]);
	minResult = min(minResult, dp[n - 1][2]);

	printf("%d\n", minResult);
}