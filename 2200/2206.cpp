#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
    int x;
    int y;
    int cnt;
    int flag;
}Node;

int arr[1001][1001] = { 0, };

int check[1001][1001] = { 0, };
int check2[1001][1001] = { 0, };

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };


int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    deque<Node> dq;
    Node now = { 1, 1, 1, 0 };
    check[1][1] = 1;
    dq.push_back(now);

    while (1)
    {
        if (dq.empty())
        {
            printf("-1\n");
            break;
        }

        now = dq.front();
        dq.pop_front();

        if (now.x == n && now.y == m)
        {
            printf("%d\n", now.cnt);
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            Node next;

            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
            next.cnt = now.cnt + 1;

            if (next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m)
            {
                if (check[next.x][next.y] == 0 && arr[next.x][next.y] == 0)
                {
                    next.flag = now.flag;
                }
                else if (check[next.x][next.y] == 0 && arr[next.x][next.y] == 1)
                {
                    next.flag = now.flag + 1;
                }
                else if (check[next.x][next.y] == 1 && arr[next.x][next.y] == 0)
                {
                    next.flag = now.flag;
                }

                if (next.flag == 0 && check[next.x][next.y] == 0)
                {   
                    dq.push_back(next);
                    check[next.x][next.y] = 1;
                }
                else if (next.flag == 1 && check2[next.x][next.y] == 0)
                {
                    dq.push_back(next);
                    check2[next.x][next.y] = 1;
                }

            }
        }

    }

}