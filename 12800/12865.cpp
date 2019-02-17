#include <iostream>

using namespace std;

int dp[100][100001] = { 0, };

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    int weight[100] = { 0, };
    int value[100] = { 0, };

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i == 0 && weight[i] <= j)
            {
                dp[i][j] = value[i];
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (weight[i] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j - weight[i]] + value[i] > dp[i-1][j] ? dp[i-1][j - weight[i]] + value[i] : dp[i-1][j] ;
            }
        }
    }

    printf("%d\n", dp[n-1][k]);

}

// // dp[i][j] = 1부터 i 번째 물건을 j 무게에서 넣었을 때의 가치

    
//         1    2   3   4   5   6   7   8   9   10  11  12
// 6,13    0    0   0   0   0   13  13  13  13  13  13  13
// 4,8     0    0   0   8   8   13  13  13  13  21  21  21
// 3,6     0    0   6   8   8   13  13  14  
// 5,12    0    0   6   8   12