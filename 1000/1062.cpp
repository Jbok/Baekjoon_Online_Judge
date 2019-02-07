#include <iostream>
#include <string.h>

using namespace std;

int check[50][26] = { { 0, }, };

int numOfReadableWords(int n, int k, int *alphabet, int *max)
{
    int result = 0;

    for (int i = 0; i < k; i++)
    {

    }

    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        
        for (int j = 0; j < 26; j++)
        {
            if (check[i][j] == 1 && alphabet[j] == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            result++;
    }
    

    return result;
}


void combination(int n, int k, int start, int end, int depth, int *arr, int *max)
{
    if (end - start < k - depth)
        return;

    if (k == depth)
    {
        int tempNum = numOfReadableWords(n ,k, arr, max);
        if (tempNum > *max)
            *max = tempNum;
        return;
    }

    for (int i = start; i < end; i++)
    {
        if (i != 'a' - 'a' && i != 'n' - 'a' && i != 't' - 'a' && i != 'i' - 'a' && i != 'c' - 'a')
        {
            arr[i] = 1;
            combination(n, k, i+1, end, depth+1, arr, max);
            arr[i] = 0;
        }
    }
}

int main()
{
    int k, n;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        char temp[16];
        cin >> temp;

        for (int j = 3; j < strlen(temp)-4; j++)
        {
            if (temp[j] != 'a' && temp[j] != 'n' && temp[j] != 't' && temp[j] != 'i' && temp[j] != 'c')
                check[i][temp[j] - 'a'] = 1;
        }
        
    }

    int alphabet[26] = { 0, };
    alphabet['a' - 'a'] = 1;
    alphabet['n' - 'a'] = 1;
    alphabet['t' - 'a'] = 1;
    alphabet['i' - 'a'] = 1;
    alphabet['c' - 'a'] = 1;
    int result = 0;
    int *pResult = &result;
    
    k = k - 5;
    combination(n, k, 0, 26, 0, alphabet, pResult);
    
    printf("%d\n", result);
}
