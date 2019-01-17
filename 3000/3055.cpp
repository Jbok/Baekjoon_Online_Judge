#include <iostream>
#include <deque>
#include <vector>

using namespace std;

typedef struct node
{
    int x;
    int y;
    int cnt;
}Node;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[51][51] = { {0, }, };
    int check[51][51] = { {0, }, };
    char map[60];

    Node start, dest;
    vector<Node> water;

    for (int i = 1; i <= n; i++)
    {
        scanf("%s", map);
        for (int j = 1; j <= m; j++)
        {
            char temp;
            temp = map[j-1];

            if (temp == 'D')
            {
                arr[i][j] = 1;
                dest.x = i;
                dest.y = j;
                check[i][j] = 10;
            }
            else if (temp == '.')
            {
                arr[i][j] = 0;
            }
            else if (temp == '*')
            {
                arr[i][j] = 2;
                water.push_back({i, j, });
                check[i][j] = 1;
            }
            else if (temp == 'S')
            {
                arr[i][j] = 3;
                start.x = i;
                start.y = j;
                check[i][j] = 1;
            }
            else if (temp == 'X')
            {
                arr[i][j] = -1;
                check[i][j] = 1;
            }
        }
    }

    deque<Node> dq;

    for (int i = 0; i < water.size(); i++)
    {
        dq.push_back(water[i]);
    }

    dq.push_back(start);

    while(1)
    {
        if (dq.empty())
        {
            printf("KAKTUS\n");
            break;
        }

        Node now = dq.front();
        dq.pop_front();

        for (int i = 0 ; i < 4 ; i++)
        {
            Node next = {now.x + dir[i][0], now.y + dir[i][1], now.cnt + 1};

            if (next.x >= 1 && next.x <=n && next.y >= 1 && next.y <= m)
            {
                if (check[next.x][next.y] == 0)
                {
                    next.cnt = now.cnt + 1;
                    dq.push_back(next);
                    check[next.x][next.y] = 1;
                    arr[next.x][next.y] = arr[now.x][now.y];
                }

                if (check[next.x][next.y] == 10 && arr[now.x][now.y] == 3)
                {
                    printf("%d\n", now.cnt + 1);
                    return 0;
                }
            }
        }
    }


    return 0;
}