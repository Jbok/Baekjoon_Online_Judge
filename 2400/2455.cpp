#include <iostream>

using namespace std;

int main()
{
    int arr[5] = { 0, };

    int max = 0;

    for (int i = 1; i <= 4; i++)
    {
        int getOn;
        int getOff;

        cin >> getOff >> getOn;

        arr[i] = arr[i-1] + getOn - getOff;

        if (arr[i] > max)
            max = arr[i];
    }

    printf("%d\n", max);
}