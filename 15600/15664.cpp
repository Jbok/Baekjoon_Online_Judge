#include <iostream>

using namespace std;

void Permutation(int n, int m, int start, int depth, int arr[], int result[], int flag[])
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

    int depthArr[10001] = {0, };

    for (int i = start; i < n; i++)
    {
        if (flag[i] == 0)
        {
            if (depthArr[arr[i]] == 0)
            {
                result[depth] = arr[i];
                depthArr[arr[i]] = 1;
                flag[i] = 1;
                Permutation(n, m, i+1, depth+1, arr, result, flag);
                flag[i] = 0;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int *arr = new int[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int temp;
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int *result = new int[m];
    int *flag = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        flag[i] = 0;
    }
    Permutation(n, m, 0, 0, arr, result, flag);

}
