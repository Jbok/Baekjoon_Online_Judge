#include <iostream>

using namespace std;

void Permutation(int n, int m, int depth, int result[], int arr[], int flag[])
{
    if (m == depth)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (flag[i] == 0)
        {
            result[depth] = arr[i];
            flag[i] = 1;
            Permutation(n, m, depth+1, result, arr, flag);
            flag[i] = 0;
        }
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    int *result = new int[m];
    int *arr = new int[n];
    int *flag = new int[n];
    

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];    
        flag[i] = 0;
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    Permutation(n, m, 0, result, arr, flag);
}
