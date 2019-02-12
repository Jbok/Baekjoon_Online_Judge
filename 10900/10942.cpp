#include <iostream>

using namespace std;

int dp[2000][2000] = { 0, };

int main()
{
    int n;
    cin >> n;

    int arr[2000] = { 0, };
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int dif = 0; dif < n; dif++)
    {
        int i = 0;
        int j = dif;

        while (1)
        {
            if (j == n)
                break;

            if (dif == 0)
            {
                dp[i][j] = 1;
            }
            else if (dif == 1)
            {
                if (arr[j] == arr[j-1])
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                if (dp[i+1][j-1] == 1 && arr[j] == arr[j-dif])
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
                
            }
            
            i++;
            j++;
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int s, e;
        scanf("%d", &s);
        scanf("%d", &e);
        printf("%d\n", dp[s-1][e-1]);
    }


}