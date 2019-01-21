#include <iostream>

using namespace std;

int check[4000001] = { 0, };
int prime[4000000] = { 0, };

int main()
{
    int n;
    cin >> n;

    int temp = 0;

    for (int i = 2; i <= n; i++)
    {
        if (check[i] == 0)
        {
            prime[temp++] = i;

            int y = i;
            int x = 2;
            while (1)
            {
                y = i * x;
                if (y > n)
                    break;
                check[y] = -1;
                x++;
            }
        }
    }

    int result = 0;

    for (int i = 0; i < temp; i++)
    {
        int sum = 0;
        for (int j = i; j < temp; j++)
        {
            sum += prime[j];
            
            if (sum == n)
            {
                result++;
                break;
            }
            if (sum > n)
            {
                break;
            }

        }
    }

    printf("%d", result);

}
