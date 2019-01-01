#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unsigned int arr[100][10];

    arr[0][0] = 0;
    for (int i = 1; i < 10; i++)
    {
        arr[0][i] = 1;
    }

    int div = 1000000000;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][0] = arr[i-1][1] % 1000000000;
            arr[i][1] = arr[i-1][0] % 1000000000 + arr[i-1][2] % 1000000000;
            arr[i][2] = arr[i-1][1] % 1000000000 + arr[i-1][3] % 1000000000;
            arr[i][3] = arr[i-1][2] % 1000000000 + arr[i-1][4] % 1000000000;
            arr[i][4] = arr[i-1][3] % div + arr[i-1][5] % div;
            arr[i][5] = arr[i-1][4] % div + arr[i-1][6] % div;
            arr[i][6] = arr[i-1][5] % div + arr[i-1][7] % div;
            arr[i][7] = arr[i-1][6] % div + arr[i-1][8] % div;
            arr[i][8] = arr[i-1][7] % div + arr[i-1][9] % div;
            arr[i][9] = arr[i-1][8] % div;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += arr[n-1][i] % div;
        sum = sum % div;
    }

    cout << sum << endl;
}
