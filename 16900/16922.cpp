#include <iostream>

using namespace std;

int value[4] = { 1, 5, 10, 50 };
int dp[21][2001] = { 0, };

int main()
{
	int n;
	cin >> n;

	dp[1][1] = 1;
	dp[1][5] = 1;
	dp[1][10] = 1;
	dp[1][50] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= 2000; j++)
		{
			if (dp[i - 1][j - 1] == 1)
				dp[i][j] = 1;

			if (dp[i - 1][j - 5] == 1)
				dp[i][j] = 1;

			if (dp[i - 1][j - 10] == 1)
				dp[i][j] = 1;

			if (dp[i - 1][j - 50] == 1)
				dp[i][j] = 1;
		}
	}

	int result = 0;

	for (int i = 0; i < 2001; i++)
	{
		if (dp[n][i] == 1)
			result++;
	}

	printf("%d\n", result);
}