#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int *arr = new int[n];
    int *inc = new int[n];
    int *dec = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        inc[i] = 1;
        dec[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[i] > arr[j] && inc[i] < inc[j] + 1)
                inc[i] = inc[j] + 1;
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = n-1; j >= i; j--)
        {
            if (arr[i] > arr[j] && dec[i] < dec[j] + 1)
                dec[i] = dec[j] + 1;
        }
    }

    int max = 0;

    for (int i = 0; i < n; i++)
    {
        max = inc[i] + dec[i] > max ? inc[i] + dec[i] : max;
    }

    cout << max - 1 << endl;
}
