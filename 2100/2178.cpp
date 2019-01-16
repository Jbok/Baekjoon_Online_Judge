#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct node
{
    int n;
    int m;
    int check = 0;
}

int arr[102][102] = { { 0, }, };
vector< vector<node> > v;
deque<node> dq;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    int check[20000] = { 0, };
    int depth[20000];

    for (int i = 0; i < 20000; i++)
    {
        depth[i] = 200000;
    }

    // Make Graph
    v.resize(11000);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 1)
            {
                node now = {1, 1};
                node next;
                if (arr[i+1][j] == 1)
                {
                    next = {now.n + 1, now.m};
                    v[now].push_back(next);
                    v[next].push_back(now);
                }

                if (arr[i-1][j] == 1)
                {
                    next = {now.n - 1, now.m};
                    v[now].push_back(next);
                    v[next].push_back(now);
                }

                if (arr[i][j+1] == 1)
                {
                    next = {now.n, now.m + 1};
                    v[now].push_back(next);
                    v[next].push_back(now);
                }

                if (arr[i][j-1] == 1)
                {
                    next = {now.n, now.m - 1};
                    v[now].push_back(next);
                    v[next].push_back(now);
                }
            }
        }
    }

    // bfs
    int node = v[{1, 1, 0}];
    int result = 1;

    dq.push_back(now);
    check[now] = 1;

    depth[now] = 1;

    while (1)
    {
        if (dq.empty())
            break;

        now = dq.front();
        dq.pop_front();
        
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            if (check[next] == 0)
            {
                dq.push_back(next);
                check[next] = 1;
                depth[next] = depth[now] + 1 < depth[next] ? depth[now] + 1 : depth[next];
            }
        }

    
    }

    cout << depth[n*(m+1) + m]  << endl;
    
}