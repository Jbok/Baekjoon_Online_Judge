#include <iostream>

using namespace std;

int arr[51][51];

void bfs(int i, int j, int w, int h)
{
    if (i < 1 || j < 1 || i > w || j > h)
    {
        return;
    }
    if (arr[j][i] == 1)
    {

        arr[j][i] = -1;
        bfs(i+1, j, w, h);
        bfs(i+1, j+1, w, h);
        bfs(i, j+1, w, h);
        bfs(i-1, j+1, w, h);
        bfs(i-1, j, w, h);
        bfs(i-1, j-1, w, h);
        bfs(i, j-1, w, h);
        bfs(i+1, j-1, w, h);
    }
}

int main()
{   
    while (1)
    {
        int w, h;
        cin >> w >> h;
        
        int max = 0;

        if (w == 0 && h == 0)
            return 0;

        for (int j = 1; j <= h; j++)
        {
            for (int i = 1; i <= w; i++)
            {
                cin >> arr[j][i];
            }
        }

        for (int i = 1; i <= w; i++)
        {
            for (int j = 1; j <= h; j++)
            {
                if (arr[j][i] == 1)
                {
                    max++;
                    bfs(i, j, w, h);
                }
            }
        }
        cout << max << endl;
    }
}
