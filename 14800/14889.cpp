#include <iostream>
#include <math.h>

using namespace std;

int arr[20][20] = { { 0, }, };

void combination(int n, int start, int depth, int *check, int *min)
{
    if (depth == n/2)
    {
        int result1 = 0;
        int result2 = 0;
        
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (check[i] == 1 && check[j] == 1)
                {
                    result1 += arr[i][j] + arr[j][i];
                }
                
                if (check[i] == 0 && check[j] == 0)
                {
                    result2 += arr[i][j] + arr[j][i];
                }
                
            }
        }
        
        int result = abs(result1 - result2);

        if (result < *min)
            *min = result;

        return;
    }

    for (int i = start; i < n; i++)
    {
        check[i] = 1;
        combination(n, i+1, depth + 1, check, min);
        check[i] = 0;
    }
}

int main()
{
    int n;
    cin >> n;

    int check[20] = { 0, };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int min = 20000;
    int *pmin = &min;

    combination(n, 0, 0, check, pmin);

    printf("%d", min);
} 