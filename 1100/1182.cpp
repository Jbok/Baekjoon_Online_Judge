#include <iostream>

using namespace std;

void Combination(int n, int s, int depth, int end, int arr[], int result[], int *count)
{
    if (n == depth){
        return;
    }

    for (int i = end; i < n; i++)
    {
        result[depth] = arr[i];
        
        int value = 0;
        for (int i = 0; i <= depth; i++){
            value += result[i];
        }
        if (value == s){
            *count += 1;
        }

        Combination(n, s, depth + 1, i + 1, arr, result, count);
    }

}


int main()
{
    int n, s;

    cin >> n >> s;

    int *arr = new int[n];
    int *result = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    int *pcount = &count;

    Combination(n, s, 0, 0, arr, result, pcount);

    printf("%d\n", count);
}
