#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n+1];
    int *dp = new int[n+1];

    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
//        dp[i] = 10000000;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j*j <= i; j++)
        {
            if (i - j*j > 0)
            {
                int temp = dp[i-1] + 1 < dp[i - j*j] + 1 ? dp[i-1] + 1 : dp[i - j*j] + 1;
                if (dp[i] > temp)
                    dp[i] = temp;
            }
            else if (i == j*j)
                dp[i] = 1;
            else
                if (dp[i] > dp[i-1] + 1)
                    dp[i] = dp[i-1] + 1;
        }
    }

    cout << dp[n] << endl;


}
