#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int check[100001] = { 0, };
    int depth[100001] = { 0, };

    deque<int> dq;

    dq.push_back(n);
    check[n] = 1;
    depth[n] = 0;

    while (1)
    {
        if (dq.empty())
            break;

        int now = dq.front();
        int nowDepth = depth[now];
        dq.pop_front();

        if (now == k)
        {
            printf("%d\n", nowDepth);
            break;
        }

        for (int i = 0; i < 3; i++)
        {
            int next, nextDepth;
            if (i == 0)
            {
                next = now;
                while (1)
                {
                    next = next * 2;
                    nextDepth = nowDepth;

                    if (next < 1 || next > 100000)
                        break;

                    if (check[next] == 0)
                    {
                        dq.push_back(next);
                        check[next] = 1;
                        depth[next] = nextDepth;
                    }
                }
            }

            else if (i == 1)
            {
                next = now + 1;
                nextDepth = nowDepth + 1;

                if (check[next] == 0 && next >= 0 && next <= 100000)
                {
                    dq.push_back(next);
                    check[next] = 1;
                    depth[next] = nextDepth;
                }
            } 
            else
            {
                next = now - 1;
                nextDepth = nowDepth + 1;

                
                if (check[next] == 0 && next >= 0 && next <= 100000)
                {
                    dq.push_back(next);
                    check[next] = 1;
                    depth[next] = nextDepth;
                }
            }   
        }
    }
}