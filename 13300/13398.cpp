#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    long long *dp1 = new long long[n];
    long long *dp2 = new long long[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        cout << arr[0] << endl;
        return 0;
    }

    dp1[0] = arr[0];
    dp2[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        if ( dp1[i-1] + arr[i] > arr[i] )
            dp1[i] = dp1[i-1] + arr[i];
        else
            dp1[i] = arr[i];
        
        if ( dp2[i-1] + arr[i] > dp1[i-1] )
            dp2[i] = dp2[i-1] + arr[i];
        else
            dp2[i] = dp1[i-1];
    }

    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        max = dp1[i] > max ? dp1[i] : max;
        max = dp2[i] > max ? dp2[i] : max;
    }

    cout << max << endl;

}
