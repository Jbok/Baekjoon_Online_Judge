#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>int v;
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

    flag[now] = 0;
}

int main()
{
    int n, m, v;
    cin >> n >> m >> vStart;


    for (int i = 0 ; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);        
    }

    dfs(vStart);
}