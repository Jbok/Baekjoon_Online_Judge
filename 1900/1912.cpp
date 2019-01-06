#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    long long *result = new long long[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        result[i] = arr[i];
    }

    int max = result[0];

    for (int i = 1; i < n; i++)
    {
        if (result[i-1] + arr[i] > arr[i])
            result[i] = result[i-1] + arr[i];

        max = result[i] > max ? result[i] : max;
    }

    cout << max << endl;

}
