#include <iostream>

using namespace std;

void Permutation(int n, int m, int depth, int start, int result[])
{
    if (m == depth)
    {
        for (int i = 0; i < depth; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < n; i++)
    {
        result[depth] = i+1;
        Permutation(n, m, depth+1, i, result);
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    int *result = new int[m];

    Permutation(n, m, 0, 0, result);
}
