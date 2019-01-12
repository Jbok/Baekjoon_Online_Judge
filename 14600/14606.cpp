#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[11] = {0, };

    for (int i = 2; i <= n; i++)
    {
        int max = 0;
        for (int j = 1; j <= i/2; j++)
        {
            if (max < j * (i-j) + arr[j] + arr[i-j])
                max = j * (i-j) + arr[j] + arr[i-j];
        }

        arr[i] = max;
    }

    cout << arr[n] << endl;
}
