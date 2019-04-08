#include <iostream>

using namespace std;

int dir[5][2] = { {0,1}, {0,-1}, {1,0}, {-1,0}, {0, 0} };
int timeTable[201][201];
int bombTable[201][201];

int main()
{
	int r, c, n;
	cin >> r >> c >> n;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			timeTable[i][j] = 999;

			char temp;
			scanf("%1c", &temp);
			
			if (temp == '\n')
				scanf("%1c", &temp);

			if (temp == '.')
			{
				bombTable[i][j] = 0;
			}
			else
			{
				bombTable[i][j] = 1;
				timeTable[i][j] = 0;
			}
		}
	}


	// 1s
	int time = 1;
	
	if (n == 1)
	{

	}
	else
	{
		while (1)
		{
			time++;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (bombTable[i][j] == 0)
					{
						bombTable[i][j] = 1;
						timeTable[i][j] = time;
					}
				}
			}

			if (time == n)
				break;

			// 3s
			time++;

			int tempTimeTable[201][201];

			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (timeTable[i][j] + 3 == time)
					{
						for (int k = 0; k < 5; k++)
						{
							int nextI = i + dir[k][0];
							int nextJ = j + dir[k][1];

							if (nextI >= 0 && nextI < r && nextJ >= 0 && nextJ < c)
							{
								tempTimeTable[nextI][nextJ] = 999;
								bombTable[nextI][nextJ] = 0;
							}
						}
					}
				}
			}

			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (timeTable[i][j] + 3 == time)
						timeTable[i][j] = tempTimeTable[i][j];
				}
			}

			if (time == n)
				break;
		}
	}
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			
			if (bombTable[i][j] == 0)
				printf(".");
			else
				printf("O");
			
			//printf("%d", timeTable[i][j]);
		}
		printf("\n");
	}

}