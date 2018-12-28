#include <iostream>

using namespace std;

void Combination(int n, int today, int date[], int price[], int value, int *max)
{
    if (today >= n)
    {
        if (value > *max)
            *max = value;
        return;
    }

    Combination(n, today+1, date, price, value, max);

    if (today + date[today] <= n)
    {
        value += price[today];
        Combination(n, today + date[today], date, price, value, max);
    }
    
}

int main()
{
    int n;
    cin >> n;

    int *date = new int[n];
    int *price = new int[n];

    int max = 0;
    int *pmax = &max;

    for (int i = 0; i < n; i++)
    {
        cin >> date[i] >> price[i];
    }

    Combination(n, 0, date, price, 0, pmax);
    cout << max << endl;
}
