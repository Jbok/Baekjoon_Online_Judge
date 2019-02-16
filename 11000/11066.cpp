#include <iostream>
#include <algorithm>

using namespace std;

long long dp[501][501] = { 0, };
int arr[501] = { 0, };
int sum[501] = { 0, };

int main()
{
    int t;
    cin >> t;

    for (int ii = 0 ; ii < t; ii++)
    {
        int k;
        cin >> k;

        for (int i = 1; i <= k; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }

        for (int dif = 1; dif < k; dif++)
        {
            int i = 1;
            int j = i + dif;

            while (1)
            {
                if (j > k)
                {
                    break;
                }

                int min = 200000000;

                for (int l = i; l < j; l++)
                {
                    int temp = sum[j] - sum[i-1] + dp[i][l] + dp[l+1][j];
                    
                    if (temp < min)
                        min = temp;
                }

                dp[i][j] = min;
                
                i++;
                j++;
            }
        }
        printf("%lld\n", dp[1][k]);
    }
}