#include <iostream>

using namespace std;

int dp[101][1001] = { 0, };

int main()
{
    int n, s, m;
    cin >> n >> s >> m;

    int arr[101] = { 0, };
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    if (s + arr[1] >= 0 && s + arr[1] <= m)
        dp[1][s + arr[1]] = 1;
    
    if (s - arr[1] >= 0 && s - arr[1] <= m)
        dp[1][s - arr[1]] = 1;
    

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            int target = arr[i];

            if (j-target >= 0 && j-target <= m && dp[i-1][j-target] == 1)
                dp[i][j] = 1;

            if (j+target >= 0 && j+target <= m && dp[i-1][j+target] == 1)
                dp[i][j] = 1;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    int result = -1;
    for (int i = m; i >= 0; i--)
    {
        if (dp[n][i] == 1)
        {
            result = i;
            break;
        }
    }

    printf("%d\n", result);
        

}