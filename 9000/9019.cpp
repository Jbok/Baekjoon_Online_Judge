#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef struct node
{
    int x;
    int cnt;
    int dir;
}Node;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;

        int check[10000] = { 0, };
        int back[10000] = { 0, };
        int dir[10000] = { 0, };

        deque<Node> dq;
        Node start = { a, 0 };
        dq.push_back(start);

        check[start.x] = 1;
        back[start.x] = -1;
        
        while (1)
        {
            if (dq.empty())
                break;

            Node now = dq.front();
            dq.pop_front();

            if (now.x == b)
            {
                int temp = b;
                char str[10000];
                int count = 0;
                while (1)
                {
                    if (temp == -1)
                        break;
                    
                    if (dir[temp] == 1)
                    {
                        str[count++] = 'D';
                    }
                    else if (dir[temp] == 2)
                    {
                        str[count++] = 'S';
                    }
                    else if (dir[temp] == 3)
                    {
                        str[count++] = 'L';
                    }
                    else if (dir[temp] == 4)
                    {
                        str[count++] = 'R';
                    }
                    temp = back[temp];
                }

                for (int j = count - 1; j >= 0; j--)
                {
                    printf("%c", str[j]);
                }
                printf("\n");

                break;
            }

            for (int i = 0; i < 4; i++)
            {
                Node next;
                if (i == 0)
                {
                    next.x = (now.x * 2) % 10000;
                }
                else if (i == 1)
                {
                    if (now.x == 0)
                    {
                        next.x = 9999;
                    }
                    else
                    {
                        next.x = now.x - 1;
                    }
                    
                }
                else if (i == 2)
                {
                    int temp = now.x / 1000;
                    next.x = (now.x * 10 + temp) % 10000;
                }
                else if (i == 3)
                {
                    int temp = now.x % 10;
                    next.x = (now.x/10 + temp*1000) % 10000;
                }

                if (check[next.x] == 0 && next.x >= 0)
                {
                    check[next.x] = 1;
                    dir[next.x] = i + 1;
                    back[next.x] = now.x;
                    next.cnt = now.cnt + 1;

                    dq.push_back(next);
                }
            }
        }

    }

}