#include <iostream>

using namespace std;

int arr[1001][1001] = { { 0, }, };
int visit[1001] = { 0, };

void dfs(int start, int n)
{
    if (visit[start])
         return;

    visit[start] = true;
    
    for (int i = 1; i <= n; i++)
    {
        if (arr[start][i] == 1)
            dfs(i, n);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    int max = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            dfs(i, n);
            max++;
        }
    }
    
    cout << max << endl;
}
