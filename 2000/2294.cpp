#include <iostream>
#include <algorithm>

using namespace std;

int dp[100][10001] = { 0, };


int main()
{
    int n, k;
    cin >> n >> k;

    int coin[100] = { 0, };

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    sort(coin, coin+n);

    int cnt = 1;
    for (int j = 1; j <= k; j++)
    {
        if (j % coin[0] == 0)
        {
            dp[0][j] = cnt++;
        }
        else
        {
            dp[0][j] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        int target = coin[i];

        for (int j = 1; j <= k; j++)
        {
            if (j < target)
            {
                dp[i][j] = dp[i-1][j];
            }
            else if (j == target)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (dp[i-1][j] == 0 && dp[i][j-target] != 0)
                {
                    dp[i][j] = dp[i][j-target] + 1;
                }
                else if (dp[i][j-target] == 0)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] < dp[i][j-target]+1 ? dp[i-1][j] : dp[i][j-target]+1;   
                }
            }         
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 1; j <= k; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    if (dp[n-1][k] == 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", dp[n-1][k]);   
    }
}
// 8
// 1 4 5

// 1   2   3   4   5   6   7   8
// 1   1   1   1   1   1   1   1
// 1   1   1   2   2   2   2   3
// 1   1   1   2   3   3   3   4

// 1   2   3   4   5   6   7   8
// 1   2   3   1   2   3   4   2
// 1   2   3   1   1   2   3   2