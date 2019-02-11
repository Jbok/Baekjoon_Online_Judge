#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

// int dir[4][2] = { { 1 , 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

void up(int n, long long (*arr)[21])
{
    for (int k = 0 ; k < n; k++)
    {
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i; j < n-1; j++)
            {
                
                // if (arr[j][k] == 0)
                // {
                int target = j;
                int move = j+1;
                while (1)
                {
                    if ( move > n-1 || target > n-1)
                        break;
                    
                    if (arr[move][k] == 0 && arr[target][k] != 0)
                    {
                        move++;
                        target++;
                    }
                    else if (arr[move][k] == 0 && arr[target][k] == 0)
                    {
                        move++;
                    }
                    else if (arr[move][k] != 0 && arr[target][k] == 0)
                    {
                        arr[target][k] = arr[move][k];
                        arr[move][k] = 0;
                        target++;
                        move++;
                    }
                    else if (arr[move][k] != 0 && arr[target][k] != 0)
                    {
                        target++;
                        move++;
                    }
                }
                // }
                
                // printf("j: %d k: %d arr[j][k]: %d arr[j+1][k]: %d\n", j, k, arr[j][k], arr[j+1][k]);
                if (arr[j][k] == arr[j+1][k])
                {
                    arr[j][k] = 2*arr[j][k];
                    arr[j+1][k] = 0;
                }
            }
        }
    }
}

void left(int n, long long (*arr)[21])
{
    for (int k = 0 ; k < n; k++)
    {
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i; j < n-1; j++)
            {

                int target = j;
                int move = j+1;
                while (1)
                {
                    if ( move > n-1 || target > n -1 )
                        break;
                    
                    if (arr[k][move] == 0 && arr[k][target] != 0)
                    {
                        move++;
                        target++;
                    }
                    else if (arr[k][move] == 0 && arr[k][target] == 0)
                    {
                        move++;
                    }
                    else if (arr[k][move] != 0 && arr[k][target] == 0)
                    {
                        arr[k][target] = arr[k][move];
                        arr[k][move] = 0;
                        target++;
                        move++;
                    }
                    else if (arr[k][move] != 0 && arr[k][target] != 0)
                    {
                        target++;
                        move++;
                    }

                }

                
                if (arr[k][j] == arr[k][j+1])
                {
                    arr[k][j] = 2*arr[k][j];
                    arr[k][j+1] = 0;
                }
            }
        }
    }
}

void down(int n, long long (*arr)[21])
{
    for (int k = 0; k < n; k++)
    {
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = i; j > 0; j--)
            {
                if (arr[j][k] == 0)
                {
                    int target = j;
                    int move = j-1;
                    while (1)
                    {
                        if ( move < 0 || target < 0 )
                            break;
                        
                        if (arr[move][k] == 0 && arr[target][k] != 0)
                        {
                            move--;
                            target--;
                        }
                        else if (arr[move][k] == 0 && arr[target][k] == 0)
                        {
                            move--;
                        }
                        else if (arr[move][k] != 0 && arr[target][k] == 0)
                        {
                            arr[target][k] = arr[move][k];
                            arr[move][k] = 0;
                            target--;
                            move--;
                        }
                        else if (arr[move][k] != 0 && arr[target][k] != 0)
                        {
                            target--;
                            move--;
                        }

                    }
                }
                
                if (arr[j][k] == arr[j-1][k])
                {
                    arr[j][k] = 2*arr[j][k];
                    arr[j-1][k] = 0;
                }
            }
        }
    }
}

void right(int n, long long (*arr)[21])
{
    for (int k = 0; k < n; k++)
    {
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = i; j > 0; j--)
            {
                if (arr[k][j] == 0)
                {
                    int target = j;
                    int move = j-1;
                    while (1)
                    {
                        if ( move < 0 || target < 0 )
                        break;
                    
                        if (arr[k][move] == 0 && arr[k][target] != 0)
                        {
                            move--;
                            target--;
                        }
                        else if (arr[k][move] == 0 && arr[k][target] == 0)
                        {
                            move--;
                        }
                        else if (arr[k][move] != 0 && arr[k][target] == 0)
                        {
                            arr[k][target] = arr[k][move];
                            arr[k][move] = 0;
                            target--;
                            move--;
                        }
                        else if (arr[k][move] != 0 && arr[k][target] != 0)
                        {
                            target--;
                            move--;
                        }
                    }
                }
                
                if (arr[k][j] == arr[k][j-1])
                {
                    arr[k][j] = 2*arr[k][j];
                    arr[k][j-1] = 0;
                }
            }
        }
    }
}

int main()
{
    string filePath = "log.txt";

    ofstream writeFile(filePath.data());
    int n;
    cin >> n;
    
    long long max = 0;

    deque<long long> dq;

    long long cnt = 0;
    dq.push_back(cnt);

    for (int i = 0 ; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            dq.push_back(temp);
        }
    }

    while (1)
    {
        cnt = dq.front();
        dq.pop_front();

        if (cnt > 5)
            break;

        long long arr[21][21];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = dq.front();
                dq.pop_front();
                if (max < arr[i][j])
                    max = arr[i][j];
            }
        }

        for (int k = 0; k < 4; k++)
        {
            long long tarr[21][21];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    tarr[i][j] = arr[i][j];
                }
            }

            if (k == 0)
            {
                up(n, tarr);
            }
            else if (k == 1)
            {
                down(n, tarr);
            }
            else if (k == 2)
            {
                left(n, tarr);
            }
            else 
            {
                right(n, tarr);
            }

            dq.push_back(cnt+1);

            writeFile << "\n=============cnt: "<< cnt-1 << " k:" << k << "\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    writeFile << tarr[i][j] << " ";
                    //printf("%d ", tarr[i][j]);
                    dq.push_back(tarr[i][j]);
                }
                writeFile << "\n";
            }
            writeFile << "\n\n";
        }
    }

    writeFile.close();

    printf("%d\n", max);
}
