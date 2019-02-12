#include <iostream>
#include <deque>

using namespace std;

int arr[100][100] = { 0, };
long long dp[100][100] = { 1, };


int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int jump = arr[i][j];

            if (jump == 0)
                break;

            if (i + jump < n)
            {   
                // printf("i: %d j: %d jump: %d\n", i, j, jump);
                dp[i+jump][j] += dp[i][j];
            }
            
            if (j + jump < n)
            {
                // printf("i: %d j: %d jump:%d\n", i, j, jump);
                dp[i][j+jump] += dp[i][j];
            }
        }
    }

    // printf("\n");
    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%ld\n", dp[n-1][n-1]);
    
}
