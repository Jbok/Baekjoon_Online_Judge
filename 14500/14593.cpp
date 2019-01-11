#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[10001][3] = { {0, }, };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] > max)
            max = arr[i][0];
    }

    int flag1[10001] = { 0, };
    int a = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == max)
        {
            flag1[i] = 1;
            a++;
            temp = i + 1;
        }
    }
    if (a == 1)
    {
        printf("%d", temp);
        return 0;
    }

    int min = 200;

    for (int i = 0; i < n; i++)
    {
        if (flag1[i] == 1 && arr[i][1] < min)
            min = arr[i][1];
    }

    a = 0;
    temp = 0;
    int flag2[10001] = { 0, };
    for (int i = 0; i < n; i++)
    {
        if ((arr[i][1] == min )&& (flag1[i] == 1))
        {
            a++;
            flag2[i] = 1;
            temp = i+1;
        }
    }
    if (a == 1)
    {
        printf("%d", temp);
        return 0;
    }

    min = 200;
    for (int i = 0; i < n; i++)
    {
        if (flag2[i] == 1 && arr[i][2] < min)
            min = arr[i][2];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i][2] == min && flag2[i] == 1)
            printf("%d", i+1);
    }

}
