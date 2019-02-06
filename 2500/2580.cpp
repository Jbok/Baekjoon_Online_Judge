#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef struct node
{
    int x;
    int y;
    int value;
}Node;

int xCheck[9][10] = { { 0, }, };
int yCheck[9][10] = { { 0, }, };
int sectorCheck[9][10] = { { 0, }, };

int main()
{
    deque<Node> dqEmpty;

    int board[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                dqEmpty.push_back({ j, i, 0 });
            }
            xCheck[j][board[i][j]] = 1;
            yCheck[i][board[i][j]] = 1;
            sectorCheck[((int)(i/3))*3 + j/3][board[i][j]] = 1;
        }
    }

    vector<Node> store;

    while (1)
    {

    // printf("start\n");    
        if (dqEmpty.empty())
            break;

        Node now = dqEmpty.front();
        dqEmpty.pop_front();

        int flag = 1;

        // printf("\nnow: [%d, %d] : %d\n", now.x, now.y, now.value);
        for (int i = now.value + 1; i < 10; i++)
        {
            // printf("    %d / %d / %d \n", xCheck[now.x][i], yCheck[now.y][i], sectorCheck[((int)(now.y/3))*3 + (int)(now.x/3)][i]);
            if (xCheck[now.x][i] == 0 && yCheck[now.y][i] == 0 && sectorCheck[((int)(now.y/3))*3 + (int)(now.x/3)][i] == 0)
            {
                xCheck[now.x][i] = 1;
                yCheck[now.y][i] = 1;
            
                sectorCheck[((int)(now.y/3))*3 + (int)(now.x/3)][i] = 1;

                board[now.y][now.x] = i;
                now.value = i;

                store.push_back(now);
                // printf("store push back: %d %d %d\n", now.x, now.y, now.value);
                flag = 0;
                break;
            }
        }
        //printf("    save value:%d flag:%d\n", now.value, flag);

        if (flag == 1)
        {
            Node before = store.back();
            dqEmpty.push_front({ now.x, now.y, 0 });
            dqEmpty.push_front(before);
            // printf("%d %d %d\n", before.x, before.y, before.value);
            xCheck[before.x][before.value] = 0;
            yCheck[before.y][before.value] = 0;
            sectorCheck[((int)(before.y/3))*3 + before.x/3][before.value] = 0;
            board[before.y][before.x] = 0;
            store.pop_back();
        }   
    }


    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

       
}