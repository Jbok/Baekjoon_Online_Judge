#include <iostream>

#define SIZE 1000

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[320][SIZE] = { { 0, }, };

    int dp[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        dp[i] = SIZE + 1;
    }

    for (int i = 1; i < 320; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            if (j > i*i)
            {
                arr[i][j] = arr[i][j - i*i] + 1;

                if (dp[j] > arr[i][j])
                    dp[j] = arr[i][j];
            }
            else if (j == i*i)
            {
                arr[i][j] = 1;
                dp[j] = 1;
            }
            else
            {
                arr[i][j] = dp[j];
            }
        }
    }

    for (int j = 1; j < 1000; j++)
    {
        printf("[%d] %d\n", j, dp[j]);

    }
    
}
