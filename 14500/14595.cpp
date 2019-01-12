#include <iostream>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    int *arr = new int[n+1];

    for (int i = 0; i < n+1; i++)
    {
        arr[i] = 0;
    }

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        arr[x]++;
        arr[y]--;
    }

    int result = 0;
    int temp = 0;
    for (int i = 1; i < n+1; i++)
    {
        temp += arr[i];

        if (temp == 0)
            result++;
    }

    cout << result << endl;

}
