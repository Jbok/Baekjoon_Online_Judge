#include <iostream>
#include <vector>

using namespace std;

int check[2001] = { 0, };
vector<vector<int>> v;
int flag = 0;

void dfs(int n, int start, int depth)
{
    if (depth == 4)
    {
        flag = 1;
        return;
    }
    
    check[start] = 1;
    for (int i = 0; i < v[start].size(); i++)
    {
        int next = v[start][i];

        if (check[next] == 0)
        {
            dfs(n, next, depth+1);
        }
    }

    check[start] = 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    v.resize(n);

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        dfs(n, i, 0);
        if (flag)
        {
            printf("1");
            return 0;
        }
    }

    printf("0");
    return 0;

}
