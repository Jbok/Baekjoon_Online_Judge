#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
    int x;
    int cnt;
}Node;

int check[100001] = { 0, };
int main()
{
    int n, k;
    cin >> n >> k;

    deque<Node> dq;

    Node start = { n, 0 };

    dq.push_back(start);

    int min = 100001;
    int result = 0;

    while (1)
    {
        if (dq.empty())
		{
			break;
		}

        Node now = dq.front();
        dq.pop_front();

        if (now.x == k)
        {
            if (now.cnt < min)
            {
                min = now.cnt;
            }
            result++;
        }

        check[now.x] = 1;

        if (now.cnt > min)
        {
            break;
        }

        for(int i = 0; i < 3; i++)
        {
            Node next;

            if (i == 0)
            {
                next.x = now.x - 1;
            }
            else if (i == 1)
            {
                next.x = now.x + 1;
            }
            else if (i == 2)
            {
                next.x = now.x * 2;
            }

            if (next.x >= 0 && next.x <= 100000)
            {
                if (check[next.x] == 0)
                {
                    next.cnt = now.cnt + 1;
                    dq.push_back(next);
                }
            }
        }
    }

    printf("%d\n%d", min, result);
}