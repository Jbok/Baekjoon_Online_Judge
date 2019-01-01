#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long arr[10001] = {0, };
    long long max[10001] = {0, };

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    max[1] = arr[1];
    max[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++)
    {
        int t1, t2, t3;
        
        t1 = max[i-2] + arr[i];
        max[i] = t1;

        t2 = max[i-3] + arr[i] + arr[i-1];
        if (max[i] < t2)
            max[i] = t2;
        
        t3 = max[i-1];
        if (max[i] < t3)
            max[i] = t3;
    }

    cout << max[n] << endl;
}

