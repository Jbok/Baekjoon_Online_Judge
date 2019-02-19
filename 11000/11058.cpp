#include <iostream>

using namespace std;

typedef struct node
{
    long long input;
    long long copy;
}Node;

int main()
{
    int n;
    cin >> n;

    Node dp[101][101] = { 0, };
    long long maxValue[101] = { 0, };

    dp[0][0] = { 0, 0 };

    dp[0][1] = { 1, 0 };
    maxValue[1] = 1;

    dp[0][2] = { 2, 0 };
    maxValue[2] = 2;

    dp[0][3] = { 3, 0 };
    dp[1][3] = { 1, 1 };
    maxValue[3] = 3;
    //printf("%d\n", dp[1][3].copy);
    dp[0][4] = { 4, 0 };
    dp[1][4] = { 2, 2 };
    maxValue[4] = 4;

    dp[0][5] = { 5, 0 };
    dp[1][5] = { 4, 2 };
    dp[2][5] = { 3, 3 };
    maxValue[5] = 5;

    dp[0][6] = { 6, 0 };
    dp[1][6] = { 6, 3 };
    dp[2][6] = { 4, 4 };
    dp[3][6] = { 6, 2 };
    maxValue[6] = 6;

    for (int i = 7; i <= n; i++)
    {
        for (int j = 0; j < i-2; j++)
        {
            if (j < i-3)
            {
                dp[j][i] = { dp[j][i-1].input + dp[j][i-1].copy, dp[j][i-1].copy };
            }
            else
            {
                dp[j][i] = { maxValue[i-2], maxValue[i-2] };
            }

            if (maxValue[i] < dp[j][i].input)
                maxValue[i] = dp[j][i].input;
        }
    }
    
    // for (int i = 0; i <= n; i++)
    // {
    //     printf("%2d ", maxValue[i]);
    // }
    // printf("\n\n");
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         printf("[%2lld, %2lld] ", dp[i][j].input, dp[i][j].copy);
    //     }
    //     printf("\n");
    // }

    printf("%lld\n", maxValue[n]);
}

// 0   1   2   3   4   5   6    7   8       9       10      11
//     1,0 2,0 3,0 4,0 5,0 6,0  6,0 6,0     6,0     6,0     6,0
//             1,1 2,2 4,2 4,4  8,4 12,4    16,4    20,4    24,4
//                     3,3 6,2  8,2 10,2    12,2    14,2    16,2
//                         6,3  9,3 12,3    15,3    18,3    21,3
//                              5,5 10,5    15,5    20,5    25,5
//                                 6,6     12,6    18,6    24,6
//                                         9,9     18,9    27,9
//                                                 12,12   24,12