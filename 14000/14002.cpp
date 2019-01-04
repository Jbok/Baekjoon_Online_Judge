#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    int *flag = new int[n];
    int *num = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        flag[i] = 1001;
    }

    int max = 0;

    for (int i = 0; i < n; i++)
    {
        bool change = false;
        for (int j = 0; j <= max; j++)
        {
            if (arr[i] <= flag[j])
            {
                flag[j] = arr[i];
                num[i] = j;
                change = true;
                break;
            }
        }
            


        if (!change)
        {
            flag[++max] = arr[i];
            num[i] = max;
        }
    }
    cout << max+1 << endl;

    int *reverse = new int[n];
    int reverseNum = 0;

    int big = max;
    for (int i = n-1; i >= 0; i--)
    {
        if (num[i] == big)
        {
            reverse[reverseNum++] = arr[i];
            big--;
        }
    }

    for (int i = reverseNum - 1; i >= 0; i--)
    {
        printf("%d ", reverse[i]);
    }
    printf("\n");
}
