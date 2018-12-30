#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n+1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = 2*n;
    }

    arr[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (2*i <= n)
        {
            if (arr[2*i] > arr[i] + 1)
                arr[2*i] = arr[i] + 1;
        }
            
        if (3*i <= n)
        {
            if (arr[3*i] > arr[i] + 1)
                arr[3*i] = arr[i] + 1;
        }
        
        if (i+1 <= n)
        {
            if (arr[i+1] > arr[i] + 1)
                arr[i+1] = arr[i] + 1;
        }
        
    }

    printf("%d\n", arr[n]);
}
