#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    int arr[31][31];

    arr[0][0] = 1;
    
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = 1;
        arr[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
        }
    }
    

    cout << arr[n-1][k-1] << endl;
}
