#include <iostream>

using namespace std;

int visit[26][26] = { { 0, }, };
int arr[26][26] = { { 0, }, };
int group[26*26] = { 0, };

void bfs(int i, int j, int n, int groupNum)
{
    if (i < 26 && j < 26 && i > 0 && j > 0)
    {
        if (visit[i][j])
            return;

        if (arr[i][j] == 1)
        {
            group[groupNum]++;
            visit[i][j] = 1;
        
            bfs(i+1, j, n, groupNum);
            bfs(i-1, j, n, groupNum);
            bfs(i, j+1, n, groupNum);
            bfs(i, j-1, n, groupNum);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int groupNum = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            bfs(i, j, n, groupNum);
            
            if (group[groupNum] != 0)
                groupNum++;
        }
    }

    for (int i = 0; i < groupNum; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (group[j] > group[i])
            {
                int temp = group[j];
                group[j] = group[i];
                group[i] = temp;
            }
        }
    }

    printf("%d\n", groupNum);
    for (int i = 0; i < groupNum; i++)
    {
        printf("%d\n", group[i]);
    }
}
