#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[301] = { 0, };

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int value[3][301] = { 0, };

    value[1][1] = arr[1];
    value[2][1] = 0;

    value[1][2] = arr[2];
    value[2][2] = value[1][1] + arr[2];

    for (int i = 3; i <= n; i++)
    {
        value[1][i] = value[2][i-2] + arr[i] > value[1][i-2] + arr[i] ? value[2][i-2] + arr[i] : value[1][i-2] + arr[i];
        value[2][i] = value[1][i-1] + arr[i];
    }

    printf("%d\n", value[1][n] > value[2][n] ? value[1][n] : value[2][n]);
}
