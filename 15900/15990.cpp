#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    unsigned int arr[100001][4] = { {0, }, };

    arr[1][1] = 1;
    arr[1][2] = 0;
    arr[1][3] = 0;
    
    arr[2][1] = 0;
    arr[2][2] = 1;
    arr[2][3] = 0;

    arr[3][1] = 1;
    arr[3][2] = 1;
    arr[3][3] = 1;

    for (int i = 4; i <= 100000; i++)
    {
        arr[i][1] = (arr[i-1][2] + arr[i-1][3]) % 1000000009;
        arr[i][2] = (arr[i-2][1] + arr[i-2][3]) % 1000000009;
        arr[i][3] = (arr[i-3][2] + arr[i-3][1]) % 1000000009;
    }

    for (int i = 1; i <= t; i++)
    {
        int temp;
        cin >> temp;
        cout << (arr[temp][1] + arr[temp][2] + arr[temp][3]) % 1000000009 << endl;
    }

}
