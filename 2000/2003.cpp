#include <iostream>
#include <algorithm>

using namespace std;

int arr2[2][10000] = { { 0, }, };

int main()
{
    int n, m;
    cin >> n >> m;

    int result = 0;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    arr2[0][0] = arr[0];
    if (arr2[0][0] == m)
        result++;

    for (int i = 1; i < n; i++)
    {   
        arr2[0][i] = arr2[0][i-1] + arr[i];
        if (arr2[0][i] == m)
            result++;
    }

    // for (int i = 0 ; i < n; i++)
    // {
    //     printf("%d ", arr2[0][i]);
    // }
    // printf("\n");


    int correction = 1;
    while (1)
    {
        if (correction > n-1)
            break;

        for (int j = correction ; j < n; j++)
        {
            arr2[1][j] = arr2[0][j] - arr2[0][correction-1];
            // printf("%d ", arr2[1][j]);
            if (arr2[1][j] == m)
                result++;
        }

        for (int j = correction; j < n; j++)
        {
            arr2[0][j] = arr2[1][j];
        }
        // printf("\n");

        correction++;
    }
    
    printf("%d\n", result);
}
