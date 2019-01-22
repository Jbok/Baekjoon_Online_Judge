#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
    int x;
    int cnt;
}Node;

int main()
{

    int check[100001] = { 0, };
    int back[100001] = { 0, };

    Node subin, sister;

    cin >> subin.x >> sister.x;
    subin.cnt = 0;
    check[subin.x] = 1;
    back[subin.x] = -1;

    deque<Node> dq;
    dq.push_back(subin);

    while (1)
    {
        if (dq.empty())
            break;

        Node now = dq.front();
        dq.pop_front();

        if (now.x == sister.x)
        {
            int temp = now.x;
            int *root = new int[now.cnt+1];
            int i = now.cnt+1;
            while (1)
            {
                root[--i] = temp;
                if (back[temp] == -1)
                    break;
                temp = back[temp];
            }

            printf("%d\n", now.cnt);

            for (int j = 0; j < now.cnt +1 ; j++)
            {
                printf("%d ", root[j]);
            }
            
            break;
        }

        Node next;
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                next.x = now.x -1;
            }
            else if (i == 1)
            {
                next.x = now.x + 1;
            }
            else if (i == 2)
            {
                next.x = now.x * 2;
            }

            if (next.x >= 0 && next.x <= 100000 && check[next.x] == 0)
            {
                check[next.x] = 1;
                back[next.x] = now.x;
                next.cnt = now.cnt + 1;
                dq.push_back(next);
            }
        }
    }

    

}
