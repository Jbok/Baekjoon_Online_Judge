#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef struct node
{
    int x;
    int cnt;
}Node;

int arr[100001][3];
int check[100001] = { 0, };

int main()
{

    int n, k;
    cin >> n >> k;


    for (int i = 0 ; i <= 100000; i++)
    {
        for (int dir = 0 ; dir < 3; dir++)
        {
            int next;
            if (dir == 0)
            {
                next = i + 1;
            }
            else if(dir == 1)
            {
                next = i - 1;
            }
            else
            {
                next = i * 2;
            }

            if (next >= 0 && next <= 100000)
            {
                arr[i][dir] = next;
            }
            else
            {
                arr[i][dir] = -1;
            }
        }
    }

    deque<Node> dq;
    dq.push_back({ n, 0 });
    check[n] = 1;

    while (1)
    {
        
        Node now = dq.front();
        dq.pop_front();

        if (now.x == k)
        {
            printf("%d", now.cnt);
            break;
        }

        for (int i = 0 ; i < 3; i++)
        {
            if (arr[now.x][i] >= 0)
            {
                Node next;
                next = { arr[now.x][i], now.cnt + 1 };
                
                if (check[next.x] == 0)
                {
                    dq.push_back(next);
                    check[next.x] = 1;
                }
            }
        }

    }

}