#include <iostream>

using namespace std;

int arr[10001] = { 0, };

int main()
{
    for (int i = 1; i <= 10000; i++)
    {
        int temp = i;
        int result = i;
        while (1)
        {
            if (temp < 1)
                break;
            int ttemp = temp % 10;
            result += ttemp;
            temp = temp / 10;
        }

        arr[result] = 1;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (arr[i] == 0)
        {
            printf("%d\n", i);
        }
    }

}

