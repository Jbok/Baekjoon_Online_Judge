#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector< vector<int> > v;
int flag[1001] = { 0, };

void dfs(int now)
{
    flag[now] = 1;
    printf("%d ", now);

    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];

        if (!flag[next])
            dfs(next);
    }
}

int main()
{
    int n, m, vStart;
    cin >> n >> m >> vStart;
    v.resize(n+1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);        
    }

    for (int i = 0; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }

    dfs(vStart);

    for (int i = 0; i <= n; i++)
        flag[i] = 0;

    cout << endl;

    // BFS
    deque<int> dq;
    dq.push_back(vStart);
    flag[vStart] = 1;

    while (1)
    {
        if (dq.empty())
            break;

        int now = dq.front();
        dq.pop_front();

        printf("%d ", now);

        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
           
            if (!flag[next])
            {
                dq.push_back(next);
                flag[next] = 1;
            }
        }
    }

}