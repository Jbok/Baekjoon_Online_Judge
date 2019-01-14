#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > v;
int check[20001] = { 0, };
int color[20001] = { 0, };
int flag = 0;

void dfs(int now)
{
    if (flag)
        return;
    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];
        if (check[next] == 0)
        {
            check[next] = 1;
            color[next] = color[now] * -1;
            dfs(next);
        }
        else if (color[next] == color[now])
            flag = 1;
    }
}

int main()
{
    int caseNum;
    cin >> caseNum;

    for (int cN = 0; cN < caseNum; cN++)
    {

        for (int i = 0; i < 20001; i++)
        {
            check[i] = 0;
            color[i] = 0;
        }

        int node, edge;
        cin >> node >> edge;
        v.clear();
        v.resize(node+1);

        flag = 0;

        int x, y;
        for (int eN = 0; eN < edge; eN++)
        {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for (int i = 1; i <= x; i++)
        {
            if (flag)
                break;
                
            if (!check[i])
            {
                check[i] = 1;
                color[i] = 1;
                dfs(i);
            }
        }
        
        if (flag)
            printf("NO\n");
        else
            printf("YES\n");

    }
}