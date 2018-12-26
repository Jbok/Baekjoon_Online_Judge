#include <iostream>

using namespace std;

int arr[10];
int input[11];
void combination(int n, int depth, int flag[], int result[], int *max, int *min)
{
    if (n == depth)
    {
        int value = input[0]; 
        for (int i = 0; i < n; i++)
        {
            
            if (result[i] == 0)
            {
                value = value + input[i+1];
            }
            else if (result[i] == 1)
            {
                value = value - input[i+1];
            }
            else if (result[i] == 2)
            {
                value = value * input[i+1];
            }
            else if (result[i] == 3)
            {
                value = value / input[i+1];
            }
        }
        if (value > *max)
            *max = value;

        if (value < *min)
            *min = value;

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (flag[i] == 0)
        {
            result[depth] = arr[i];
            flag[i] = 1;
            combination( n, depth + 1, flag, result, max, min );
            flag[i] = 0;
        }
    }
}   


int main()
{
    int n;
    cin >> n;
    
    int flag[10] = {0, };
    int result[10] = {0, };

    int min = 1000000000;
    int max = -1000000000;

    int *pmin = &min;
    int *pmax = &max;


    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k = 0;
    for (int j = 0; j < 4; j++)
    {
        int temp;
        cin >> temp;
        
        while (temp != 0)
        {
            arr[k++] = j;
            temp--;
        }
    }

    combination(n-1, 0, flag, result, pmax, pmin);

    printf("%d\n%d\n", max, min);
}
