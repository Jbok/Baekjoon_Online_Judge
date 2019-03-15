#include <iostream>

using namespace std;

int arr[1001][1001];

int main()
{
    int t;
    cin >> t;

    for (int cnt = 0; cnt < t; cnt++)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);

            arr[a][b] = 1;
            arr[b][a] = 1;
        }

        printf("%d\n", n-1);
    }


}