#include <iostream>

using namespace std;

int leftCross[2][15] = { { 0, }, };
int upCross[30] = { 0, };
int row[15] = { 0, };
int col[15] = { 0, };

void dfs(int n, int depth, int *result)
{
    if (depth == n)
    {
        *result = *result + 1;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int k = i - depth;
        int p = 0;
        if (k < 0)
            p = 1;
        
        k = abs(k);

        if (row[i] == 0 && col[depth] == 0 && upCross[i+depth] == 0 && leftCross[p][k] == 0)
        {
            row[i] = 1;
            col[depth] = 1;
            upCross[i+depth] = 1;
            leftCross[p][k] = 1;
            dfs(n, depth + 1, result);

            row[i] = 0;
            col[depth] = 0;
            upCross[i+depth] = 0;
            leftCross[p][k] = 0;

        }
    }
}

int main()
{
    int n;
    cin >> n;

    int max = 0;
    int *pmax = &max;

    dfs(n, 0, pmax);
    printf("%d\n", max);

}