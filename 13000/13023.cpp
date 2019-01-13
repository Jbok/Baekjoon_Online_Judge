#include <iostream>

using namespace std;

int arr[2000][2000] = { { 0, }, };
int flag = 0;

void dfs(int n, int start, int depth, int *check)
{
    if (depth == 4)
    {
        flag = 1;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0 && arr[start][i] == 1)
        {
            check[i] = 1;
            dfs(n, i, depth+1, check);
            check[i] = 0;
        }
    }

}

int main()
{
    int n, m;
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    int check[2000] = { 0, };

    for (int i = 0; i < n; i++)
    {
        check[i] = 1;
        dfs(n, i, 0, check);
        if (flag)
        {
            printf("1");
            return 0;
        }
        check[i] = 0;
    }

    printf("0");
    return 0;

}
