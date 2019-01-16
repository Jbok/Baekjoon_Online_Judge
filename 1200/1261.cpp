#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
    int x;
    int y;
    int cnt;
}Node;

int arr[101][101] = { { 0, }, };
int check[101][101] = { { 0, }, };
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main()
{
    int n, m;
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    deque<Node> dq;

    Node now = {1, 1, 0};
    dq.push_back(now);

    while (1)
    {
        if (dq.empty())
            break;

        now = dq.front();
        dq.pop_front();

        if (now.x == n && now.y == m)
        {
            printf("%d\n", now.cnt);
            break;
        }

        Node next;
        for (int i = 0; i < 4; i ++)
        {
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
    
            if (next.x >= 1 && next.x <= n && next.y >=1 && next.y <= m && check[next.x][next.y] == 0)
            {
                check[next.x][next.y] = 1;
        
                if (arr[next.x][next.y] == 0)
                {
                    next.cnt = now.cnt;            
                    dq.push_front(next);
                }
                else
                {
                    next.cnt = now.cnt + 1;
                    dq.push_back(next);
                }
            }
        }
        
    }

    return 0;
}
