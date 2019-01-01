#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[1002][10] = { {0, }, };

    for (int i = 0; i < 10; i++)
    {
        arr[0][i] = 1;
    }

    for (int i = 1; i < 1000; i++)
    {   
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                arr[i][j] = (arr[i][j] + arr[i-1][k]) % 10007;
            }
        }
    }


    int result = 0;
    
    for (int i = 0; i < 10; i++)
        result = (result + arr[n-1][i]) % 10007;

    cout << result;
}
