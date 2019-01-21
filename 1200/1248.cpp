#include <iostream>

using namespace std;

char arr[10][10];

void dfs(int n, int depth, int *target, int *finish)
{
    if (n == depth)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", target[i]);
        }
        printf("\n");
        *finish = 1;
        return;
    }


    for(int i = -10; i < 11; i++)
    {
        target[depth] = i;

        int flag = 1;
        for (int i = 0; i <= depth; i++)
        {
            int temp = 0;
            for (int j = i; j <= depth; j++)
            {
                temp += target[j];

                //printf("temp= %d target[j] = %d \n", temp, target[j]);

                if (temp == 0)
                {
                    //printf("temp == 0\n");
                    if (arr[i][j] != '0')
                    {
                        flag = 0;
                        break;
                    }
                }
                
                if (temp > 0)
                {
                    //printf("temp > 0\n");
                    if (arr[i][j] != '+')
                    {
                        flag = 0;
                        break;
                    }
                }
                
                if (temp < 0)
                {
                    //printf("temp < 0\n");
                    if (arr[i][j] != '-')
                    {
                        flag = 0;
                        break;
                    }
                }
            }

            if (flag == 0)
                break;
        }

        if (flag)
            dfs(n, depth+1, target, finish);

        if (*finish)
            return;
    }
}


int main()
{
    int n;
    cin >> n;

    char str[1000];
    scanf("%s", str);


    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            arr[i][j] = str[temp++];
        }
    }

    int *target = new int[n];

    int finish = 0;
    int *pfinish = &finish;

    dfs(n, 0, target, pfinish);

}