#include <iostream>
#include <cstdio>

using namespace std;

int dp[2][41] = { {0, }, };

int main()
{
	dp[0][0] = 1;
	dp[1][0] = 0;
	dp[0][1] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= 40; i++)
	{
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
		dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		printf("%d %d\n", dp[0][temp], dp[1][temp]);
	}
	


}