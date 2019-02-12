#include <iostream>
#include <deque>

using namespace std;

int arr[100][100] = { { 0, }, };

typedef struct node
{
    int x;
    int y;
}Node;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    deque<Node> dq;

    int jump = 0 + arr[0][0];

    if (jump < n)
    {
        dq.push_back( { jump, 0 } );
        dq.push_back( { 0, jump } );
    }

    int result = 0;

    while (1)
    {
        if (dq.empty())
            break;

        Node now = dq.front();
        dq.pop_front();

        jump = arr[now.y][now.x];

        if (jump == 0)
        {
            result++;
        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                Node next;
                if (i == 0)
                {
                    if (now.y + jump < n)
                    {
                        dq.push_back( { now.x, now.y + jump } );
                    }
                }
                else if (i == 1)
                {
                    if (now.x + jump < n)
                    {
                        dq.push_back( { now.x + jump, now.y } );
                    }
                }
            }
        }
        
        
    }

    printf("%d\n", result);
}