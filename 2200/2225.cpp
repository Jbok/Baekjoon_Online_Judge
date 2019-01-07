#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    long long arr[201][201] = { { 0, }, };

    for (int i = 1; i <= n; i++)
    {
        arr[1][i] = 1;
    }

    for (int i = 1; i <= k; i++)
    {
        arr[i][0] = 1;
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int l = 0; l <= j; l++)
            {
                arr[i][j] += arr[i-1][l] % 1000000000;
            }
        }
    }

    cout << arr[k][n] % 1000000000 << endl;
}
