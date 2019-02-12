#include <iostream>

using namespace std;

int arr[1000][1000] = { { 0, }, };
int value[1000][1000] = { { 0, }, };

int main()
{
    int max = 0;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    value[0][0] = arr[0][0];

    for (int i = 1; i < m; i++)
    {
        value[0][i] = value[0][i-1] + arr[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        value[i][0] = value[i-1][0] + arr[i][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int v1 = arr[i][j] + value[i][j-1];
            int v2 = arr[i][j] + value[i-1][j];

            value[i][j] = v1 > v2 ? v1 : v2;
        }
    }

    // printf("\n\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         printf("%2d ", value[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", value[n-1][m-1]);


}