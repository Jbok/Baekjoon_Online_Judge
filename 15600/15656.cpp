#include <iostream>

using namespace std;

void Permutation(int n, int m, int depth, int arr[], int result[])
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
        result[depth] = arr[i];
        Permutation(n, m, depth+1, arr, result);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int *arr = new int[n];
    int *result = new int[m];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
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

    Permutation(n, m, 0, arr, result);
}
