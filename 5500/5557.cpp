#include <iostream>

using namespace std;

int arr[101] = { 0, };
long long dp[101][21] = { 0, };

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    long long target = arr[1];
    dp[1][target] = 1;

    for (int i = 2; i <= n ; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            long long target = arr[i];

            if (j+target >= 0 && j+target <= 20)
                dp[i][j] += dp[i-1][j+target];
            
            if (j-target >= 0 && j-target <= 20)
                dp[i][j] += dp[i-1][j-target];
        }
    }

    target = arr[n];
    printf("%lld\n", dp[n-1][target]);
}