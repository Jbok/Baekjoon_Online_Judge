#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[1001] = { 0, };
    int flag[1001];

    for (int i = 0; i < 1001; i++)
    {
        flag[i] = 1001;
    }

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        bool change = false;

        for (int j = 0; j < max; j++)
        {
           if (arr[i] <= flag[j])
           {
               flag[j] = arr[i];
               change = true;
               break;
           }
        }

        if (!change)
            flag[max++] = arr[i];
    }

    cout << max << endl;
}
