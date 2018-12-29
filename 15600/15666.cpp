#include <iostream>

using namespace std;

void Permutation(int n, int m, int start, int depth, int arr[], int result[])
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

    for (int i = start; i < n; i++)
    {
        result[depth] = arr[i];
        Permutation(n, m, i, depth+1, arr, result);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int *arr = new int[n];

    int num = 0;

    for (int i = 0; i < n; i++)
    {
        int target;
        cin >> target;

        bool flag = true;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] == target)
                flag = false;
        }

        if (flag){
            arr[num++] = target;
        }
    }

    for (int i = 0; i < num-1; i++)
    {
        for (int j = i; j < num; j++)
        {
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }


    int *result = new int[m];
    Permutation(num, m, 0, 0, arr, result);

}
