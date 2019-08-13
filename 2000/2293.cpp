#include <iostream>
#include <algorithm>

using namespace std;

int cnt[2][10001] = { 0, };

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[100] = { 0, };

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for (int j = 1; j <= k; j++)
    {
        if (j % arr[0] == 0)
        {
            cnt[0][j] = 1;
        }
        else
        {
            cnt[0][j] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (arr[i] > j)
            {
                cnt[1][j] = cnt[0][j];
            }
            else if (arr[i] == j)
            {
                cnt[1][j] = cnt[0][j] + 1;
            }
            else
            {
                cnt[1][j] = cnt[0][j] + cnt[1][j-arr[i]];
            }
        }

        for (int j = 1; j <= k; j++)
        {
            cnt[0][j] = cnt[1][j];
        }
    }

    printf("%d\n", cnt[0][k]);

}