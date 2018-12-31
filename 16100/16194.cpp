#include <iostream>

using namespace std;

int main()
{
    int n; 
    cin >> n;

    int price[1001] = {0, };

    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int temp = price[j] + price[i-j];
            if (price[i] > temp)
                price[i] = temp;
        }
    }

    cout << price[n] << endl;
}
