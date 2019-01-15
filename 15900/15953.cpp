#include <iostream>

using namespace std;

int priceFirst(int rank)
{
    int price;
    if (rank == 0)
        price = 0;
    else if (rank <= 1)
        price = 500;
    else if (rank <= 3)
        price = 300;
    else if (rank <= 6)
        price = 200;
    else if (rank <= 10)
        price = 50;
    else if (rank  <= 15)
        price = 30;
    else if (rank  <= 21)
        price = 10;
    else
        price = 0;

    return price;
}

int priceSecond(int rank)
{
    int price;
    if (rank == 0)
        price = 0;
    else if (rank <= 1)
        price = 512;
    else if (rank <= 3)
        price = 256;
    else if (rank <= 7)
        price = 128;
    else if (rank <= 15)
        price = 64;
    else if (rank <= 31)
        price = 32;
    else
        price = 0;

    return price;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        
        int result = priceFirst(a) + priceSecond(b);
        result *= 10000;
        printf("%d\n", result);
    }
}
