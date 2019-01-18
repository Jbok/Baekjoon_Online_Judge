#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int digit = 0;
    
    int target[6] = { 0, };
    int upResult[6] = { 0, };
    int downResult[6] = { 0, };

    int check[10] = { 0, };


    int temp = n;
    while (1)
    {
        int number = temp % 10;
        target[digit++] = number;

        temp = temp / 10;
        if (temp == 0)
        {
            break;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int number;
        cin >> number;

        check[number] = 1;
    }

    int a = -1;

    int flag[2] = {0, 0};

    int up;
    int down;

    printf("digit: %d\n", digit);

    for (int i = digit-1; i >= 0; i--)
    {
        int number = target[i];
        
        up = number + 1;
        down = number - 1;

        if (check[number] == 1)
        {
            while (1)
            {

                if (flag[0] == 1 && flag[1] == 1)
                    break;

                if (up > 9 || down < 0)
                    break;

                if (flag[0] == 0 && check[up] == 0)
                {
                    flag[0] = 1;
                }
                else if (flag[0] == 0 && check[up] == 1)
                {
                    up++;
                }

                if (flag[1] == 0 && check[down] == 0)         
                {
                    flag[1] = 1;
                }
                else if (flag[1] == 0 && check[down] == 1)
                {
                    down--;
                }
            }
            
            printf("number : %d digit : %d up: %d down : %d \n", number, i, up, down);
            a = i;
            break;
        }
        else
        {
            upResult[i] = number;
            downResult[i] = number;
        }
    }


    upResult[a] = up;
    downResult[a] = down;

    for (int i = 0; i < a; i++)
    {

        printf("for up: %d down : %d\n", up, down);
        if (flag[0] == 1)
        {
            upResult[i] = down;
        }
        
        if (flag[1] == 1)
        {
            downResult[i] = up;
        }
    }


    printf("a: %d\n", a);
    for (int i = 0; i < digit; i++)
    {
        printf("%d ", upResult[i]);
    }
    cout << endl;

    for (int i = 0; i < digit; i++)
    {
        printf("%d ", downResult[i]);
    }
    cout << endl;
    int uR = 0;
    int dR = 0;
    
    for (int i = 1; i < digit; i++)
    {
        int ten = 1;
        for (int j = 1; j < i; j++)
        {
            ten = ten * 10;
        }
        if (flag[0] == 1)
        {
            uR += ten * upResult[i];
        }

        if (flag[1] == 1)
        {
            dR += ten * downResult[i];
        }
    }



    if (flag[0] == 1)
        printf("%d\n", uR);

    if (flag[1] == 1)
        printf("%d\n", dR);


    int result;

    if (flag[0] == 1 && flag[1] == 0)
    {
        result = uR;
    }
    else if (flag[0] == 0 && flag[1] == 1)
    {
        result = dR;
    }
    else if (flag[0] == 1 && flag[1] == 1)
    {
        result = uR - n < n - dR ? uR : dR;
    }

    printf("result : %d\n ", result);
}