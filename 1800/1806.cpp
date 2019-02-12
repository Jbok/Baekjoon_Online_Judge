#include <iostream>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min = 111111;

    int start = 0;
    int end = 0;

    int sum = arr[start];

    while (1)
    {
        
        while (1)
        {
            if (end == n)
                break;

            if (sum >= s)
            {
                if (min > end - start + 1)
                {
                    min = end - start + 1;
                }
                break;
            }

            sum += arr[++end];
        }

        sum -= arr[start++];
        if (start == n)
            break;
    }

    if (min == 111111)
        printf("0\n");
    else
    {
        printf("%d\n", min);
    }
    
}
