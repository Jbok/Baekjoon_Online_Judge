nclude <iostream>

using namespace std;

int main()
{
        int n, m, x, y, k;
            cin >> n >> m >> y >> x >> k;

                int map[21][21] = { 0, };

                    for (int i = 0; i < n; i++)
                            {
                                        for (int j = 0; j < m; j++)
                                                    {
                                                                    cin >> map[i][j];
                                                                            }
                                            }

                        int order[1000] = { 0, };
                            for (int i = 0; i < k; i++)
                                    {
                                                cin >> order[i];
                                                    }

                                int dice[5][5] = { 0, };

                                    for (int i = 0; i < k; i++)
                                            {
                                                        int dir = order[i];
                                                                int flag = 1;

                                                                        if (dir == 1 && x+1 < m)
                                                                                    {
                                                                                                    x = x + 1;
                                                                                                                dice[2][0] = dice[2][1];
                                                                                                                            dice[2][1] = dice[2][2];
                                                                                                                                        dice[2][2] = dice[2][3];
                                                                                                                                                    dice[2][3] = dice[2][4];

                                                                                                                                                                dice[2][4] = dice[2][0];
                                                                                                                                                                            dice[0][2] = dice[2][0];
                                                                                                                                                                                        dice[4][2] = dice[2][0];
                                                                                                                                                                                                }
                                                                                else if (dir == 2 && x-1 >= 0)
                                                                                            {
                                                                                                            x = x - 1;
                                                                                                                        dice[2][4] = dice[2][3];
                                                                                                                                    dice[2][3] = dice[2][2];
                                                                                                                                                dice[2][2] = dice[2][1];
                                                                                                                                                            dice[2][1] = dice[2][0];

                                                                                                                                                                        dice[2][0] = dice[2][4];
                                                                                                                                                                                    dice[0][2] = dice[2][4];
                                                                                                                                                                                                dice[4][2] = dice[2][4];
                                                                                                                                                                                                        }
                                                                                        else if (dir == 3 && y-1 >= 0)
                                                                                                    {
                                                                                                                    y = y - 1;
                                                                                                                                dice[4][2] = dice[3][2];
                                                                                                                                            dice[3][2] = dice[2][2];
                                                                                                                                                        dice[2][2] = dice[1][2];
                                                                                                                                                                    dice[1][2] = dice[0][2];

                                                                                                                                                                                dice[0][2] = dice[4][2];
                                                                                                                                                                                            dice[2][0] = dice[4][2];
                                                                                                                                                                                                        dice[2][4] = dice[4][2];
                                                                                                                                                                                                                }
                                                                                                else if (dir == 4 && y+1 < n)
                                                                                                            {
                                                                                                                            y = y + 1;
                                                                                                                                        dice[0][2] = dice[1][2];
                                                                                                                                                    dice[1][2] = dice[2][2];
                                                                                                                                                                dice[2][2] = dice[3][2];
                                                                                                                                                                            dice[3][2] = dice[4][2];

                                                                                                                                                                                        dice[4][2] = dice[0][2];
                                                                                                                                                                                                    dice[2][0] = dice[0][2];
                                                                                                                                                                                                                dice[2][4] = dice[0][2];
                                                                                                                                                                                                                        }
                                                                                                        else
                                                                                                                    {
                                                                                                                                    flag = 0;
                                                                                                                                            }

                                                                                                                if (flag == 1)
                                                                                                                            {
                                                                                                                                            if (map[y][x] == 0)
                                                                                                                                                            {
                                                                                                                                                                                map[y][x] = dice[2][2];
                                                                                                                                                                                            }
                                                                                                                                                        else
                                                                                                                                                                        {
                                                                                                                                                                                            dice[2][2] = map[y][x];
                                                                                                                                                                                                            map[y][x] = 0;
                                                                                                                                                                                                                        }
                                                                                                                                                        /*
                                                                                                                                                         *
                                                                                                                                                         *          printf("=============\n");
                                                                                                                                                         *                      for (int i = 0; i < 5; i++)
                                                                                                                                                         *                                  {
                                                                                                                                                         *                                                  for (int j = 0; j < 5; j++)
                                                                                                                                                         *                                                                  {
                                                                                                                                                         *                                                                                      printf("%d ", dice[i][j]);
                                                                                                                                                         *                                                                                                      }
                                                                                                                                                         *                                                                                                                      printf("\n");
                                                                                                                                                         *                                                                                                                                  }
                                                                                                                                                         *                                                                                                                                              printf("=============\n");
                                                                                                                                                         *                                                                                                                                              */
                                                                                                                                                                    printf("%d\n", dice[0][2]);
                                                                                                                                                                            }

                                                                                                                    }
}
