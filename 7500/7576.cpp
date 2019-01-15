#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef struct node
{
    int x;
    int y;
    int cnt = 0;
}Node;

vector< vector<Node> > v;
deque<Node> dq;

Node dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

Node start[1100000] = { {0, 0}, };
int startNum = 0;

int arr[1001][1001] = { { 0, }, };

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                dq.push_back({i, j});
                arr[i][j] = -1;
            }
        }
    }

    int max = 0;
    while (1)
    {
        if (dq.empty())
            break;

        Node now = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++)
        {
            Node next = { now.x + dir[i].x, now.y + dir[i].y };
            if ( next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= m)
            {
                if (arr[next.x][next.y] == 0)
                {
                    next.cnt = now.cnt + 1;
                    dq.push_back(next);
                    arr[next.x][next.y] = -1;

                    if (max < next.cnt)
                        max = next.cnt;
                }
            }
        }    
    }

    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 0)
                flag = 1;
        }
    }

    if (flag)
        printf("-1\n");
    else
    {
        printf("%d", max);
    }

}
