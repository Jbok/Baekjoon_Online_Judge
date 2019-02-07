#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
    int x;
    int y;
}Node;

typedef struct ball
{
    Node red;
    Node blue;
    int cnt;
}Ball;

int dir[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int main()
{
    int n, m;
    cin >> n >> m;

    char board[10][10];

    Node red, blue, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'B')
            {
                blue.x = j;
                blue.y = i;
                board[i][j] = '.';
            }

            if (board[i][j] == 'R')
            {
                red.x = j;
                red.y = i;
                board[i][j] = '.';
            }

            if (board[i][j] == 'O')
            {
                end.x = j;
                end.y = i;
            }
        }
    }

    Ball target;
    target.blue = blue;
    target.red = red;
    target.cnt = 0;

    deque<Ball> dq;
    dq.push_back(target);

    while (1)
    {
        if (dq.empty())
        {
            printf("-1\n");
            break;        
        }

        Ball now = dq.front();
        dq.pop_front();

        Node nowRed = now.red;
        Node nowBlue = now.blue;

        if (now.cnt == 10)
        {
            printf("-1\n");
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            Node nextRed;
            nextRed.x = nowRed.x;
            nextRed.y = nowRed.y;

            Node nextBlue;
            nextBlue.x = nowBlue.x;
            nextBlue.y = nowBlue.y;

            int flag = 0;

            while (1)
            {
                if (board[nextRed.y + dir[i][0]][nextRed.x + dir[i][1]] == 'O')
                {   
                    nextRed.x = nextRed.x + dir[i][1];
                    nextRed.y = nextRed.y + dir[i][0];
                    flag = 1;
                    break;
                }
                else if (nextRed.y + dir[i][0] == nowBlue.y && nextRed.x + dir[i][1]  == nowBlue.x)
                {
                    break;
                }
                else if (board[nextRed.y + dir[i][0]][nextRed.x + dir[i][1]] == '.')
                {
                    nextRed.x = nextRed.x + dir[i][1];
                    nextRed.y = nextRed.y + dir[i][0];
                }
                else
                {
                    break;
                }
            }

            while (1)
            {
                if (board[nextBlue.y + dir[i][0]][nextBlue.x + dir[i][1]] == 'O')
                {   
                    flag = 2;
                    break;
                }
                else if (nextBlue.y + dir[i][0] == nextRed.y && nextBlue.x + dir[i][1] == nextRed.x )
                {
                    break;
                }
                else if (board[nextBlue.y + dir[i][0]][nextBlue.x + dir[i][1]] == '.')
                {
                    nextBlue.x = nextBlue.x + dir[i][1];
                    nextBlue.y = nextBlue.y + dir[i][0];
                }
                else
                {
                    break;
                }
            }

            while (1)
            {
                if (board[nextRed.y + dir[i][0]][nextRed.x + dir[i][1]] == 'O')
                {   
                    if (flag == 2)
                        flag = 2;
                    else
                        flag = 1;
                    break;
                }
                else if (nextRed.y + dir[i][0] == nextBlue.y && nextRed.x + dir[i][1]  == nextBlue.x)
                {
                    break;
                }
                else if (board[nextRed.y + dir[i][0]][nextRed.x + dir[i][1]] == '.')
                {
                    nextRed.x = nextRed.x + dir[i][1];
                    nextRed.y = nextRed.y + dir[i][0];
                }
                else
                {
                    break;
                }
            }


            // printf("[%d] %d %d %d %d\n", now.cnt, nextRed.x, nextRed.y, nextBlue.x, nextBlue.y);
            // Sleep(1000);
            if (flag == 1)
            {
                printf("%d\n", now.cnt+1);
                return 0;
            }else if (flag == 2)
            {

            }
            else if (nowRed.x == nextRed.x && nowRed.y == nextRed.y && nowBlue.x == nextBlue.x && nowBlue.y == nextBlue.y)
            {

            }
            else
            {
                Ball nextTarget = { nextRed, nextBlue, now.cnt + 1 };
                dq.push_back(nextTarget);
            }
            
        }
       
    }


}