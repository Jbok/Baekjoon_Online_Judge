#include <iostream>

using namespace std;

int expTime[101] = { 0, };
int score[101] = { 0, };

int dp[101][10001] = { 0, };

int main()
{
    int n, t;
    cin >> n >> t;

    for (int i = 1; i <= n; i++)
    {
        cin >> expTime[i] >> score[i];
    }

    for (int i = 0; i <= t; i++)
    {
        int tempTime = expTime[1];
        int tempScore = score[1];

        if (i < tempTime)
            dp[1][i] = 0;
        else
        {
            dp[1][i] = tempScore;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            int tempTime = expTime[i];
            int tempScore = score[i];

            if (j < tempTime)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j-tempTime] + tempScore > dp[i-1][j] ? dp[i-1][j-tempTime] + tempScore : dp[i-1][j];
            }
        }
    }

    printf("%d\n", dp[n][t]);

}
