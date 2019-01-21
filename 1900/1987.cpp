#include <iostream>

using namespace std;

char arr[20][20];

typedef struct node
{
    int x;
    int y;
}Node;

int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

void dfs(int r, int c, Node now, int depth, int *check, int *max)
{
    if (*max < depth)
        *max = depth;

    Node next;
    for (int i = 0; i < 4; i++)
    {
        next.x = now.x + dir[i][0];
        next.y = now.y + dir[i][1];

        if (next.x >= 0 && next.x < r && next.y >= 0 && next.y < c)
        {
            char ch = arr[next.x][next.y];
            if (check[ch- 'A'] == 0)
            {
                check[ch - 'A'] = 1;
                dfs(r, c, next, depth+1, check, max);
                check[ch - 'A'] = 0;
            }
        }
    }
}

int main()
{
    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    int check[30] = { 0, };

    int max = 0;
    int *pmax = &max;

    char ch = arr[0][0];
    check[ch -'A'] = 1;

    dfs(r, c, { 0, 0 }, 1, check, pmax);
  

    printf("%d", max);
}