#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    int *d = new int[n];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        d[i] = arr[i];

        for (int j = 0; j <= i; j++)
        {
            if ( d[j] < d[i] && d[j]  + arr[i] > d[i] )
            {
                d[i] = d[j] + arr[i];
            }
        }
       
        ans = ans > d[i] ? ans : d[i];
    }

    cout << ans << endl;
}
