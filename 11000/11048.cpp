#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
    int x;
    int y;
    int value;
}Node;

int arr[1000][1000] = { { 0, }, };
int value[1000][1000] = { { 0, }, };
int dir[2][2] = { { 1, 0 }, { 0, 1} };

int main()
{
    int max = 0;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    Node start = { 0, 0, arr[0][0] };

    deque<Node> dq;
    dq.push_back(start);

    while (1)
    {
        if (dq.empty())
            break;
        
        Node now = dq.front();
        dq.pop_front();
        
        if (max < now.value)
            max = now.value;

        for (int i = 0; i < 2; i++)
        {
            Node next;
            int nextX = now.x + dir[i][0];
            int nextY = now.y + dir[i][1];

            if (nextX < n && nextY < m)
            {
                int nextV = now.value + arr[nextX][nextY];
                next = { now.x + dir[i][0], now.y + dir[i][1], nextV };
                dq.push_back(next);
            }
        }
    }

    printf("%d\n", max);

}