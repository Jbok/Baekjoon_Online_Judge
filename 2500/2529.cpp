#include <iostream>

using namespace std;

char minarr[11] = { 0, };
char maxarr[11] = { 0, };
char str[11];

void dfs(int n, int depth, int *check, int *arr, long long *max, long long *min)
{
    if (n == depth)
    {
        long long result = 0;
        long long ten = 1;
        for (int i = n-1; i >= 0; i--)
        {
            result += arr[i] * ten;
            ten = ten * 10;
        }

        if (result < *min)
        {
            *min = result;
            for (int i = 0; i < n; i++)
            {
                minarr[i] = '0'+arr[i];
            }
        }

        if (result > *max)
        {
            *max = result;
            for (int i = 0; i < n; i++)
            {
                maxarr[i] = '0'+arr[i];
            }
        }
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        int flag = 1;
        if (check[i] == 0)
        {
            check[i] = 1;
            arr[depth] = i;

            if (depth > 0)
            {
                if (str[depth-1] == '<')
                {
                    if (arr[depth-1] > arr[depth])
                        flag = 0;
                }

                if (str[depth-1] == '>')
                {
                    if (arr[depth-1] < arr[depth])
                        flag = 0;
                }
            }
            
            if (flag)
                dfs(n, depth+1, check, arr, max, min);
            check[i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    int check[11] = { 0, };
    int arr[11] = { 0, };

    long long min = 9999999999;
    long long max = 0;
    long long *pmin = &min;
    long long *pmax = &max;

    dfs(n+1, 0, check, arr, pmax, pmin);
    
    printf("%s\n", maxarr);
    printf("%s\n", minarr);


}