#include <iostream>

using namespace std;

int arr[100][100] = { 0, };

int IsPossible(int n, int l, int *arr)
{
    int temp[100] = { 0, };

    int before = arr[0];

    int i = 1;
    while (1)
    {
        if (i >= n)
            break;

        
        if (before < arr[i] - 1 || before > arr[i] + 1)
        {
            return -1;
        }

        if (before == arr[i] - 1)
        {
            if (i-l < 0)
            {
                return -1;
            }

            for (int k = 1; k <= l; k++)
            {
                if (arr[i-k] != before)
                    return -1;
            }
            
            for (int k = 1; k <= l; k++)
            {
                if (temp[i-k] == 0)
                {
                    temp[i-k] = 1;
                }
                else
                {
                    return -1;
                }
            }
        }
        else if (before == arr[i] + 1)
        {
            if (i+l > n)
            {
                return -1;
            }

            for (int k = 1; k < l; k++)
            {
                if (arr[i+k] + 1 != before)
                    return -1;
            }

            for (int k = 0; k < l; k++)
            {
                if (temp[i+k] == 0)
                {
                    temp[i+k] = 1;
                }
                else
                {
                    return -1;
                }            
            }
        }
        else
        {
     
        }
        before = arr[i];
        i++;       
    }

    return 1;
}

int main()
{
    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (IsPossible(n, l, arr[i]) == 1)
        {
            result++;
            // printf("arr[i]: %d\n", i);
        }
            
    }

    int temp[100] = { 0, };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j] = arr[j][i];
        }

        if (IsPossible(n, l, temp) == 1)
        {
            result++;
            // printf("arr[j][i]: %d\n", i);
        }
            
    }

    printf("%d\n", result);
}

//  11211