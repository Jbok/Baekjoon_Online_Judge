#include <iostream>

using namespace std;

int wheel[5][8] = { 0, };

void Clockwise(int wN)
{
	int temp = wheel[wN][0];
	wheel[wN][0] = wheel[wN][7];
	wheel[wN][7] = wheel[wN][6];
	wheel[wN][6] = wheel[wN][5];
	wheel[wN][5] = wheel[wN][4];
	wheel[wN][4] = wheel[wN][3];
	wheel[wN][3] = wheel[wN][2];
	wheel[wN][2] = wheel[wN][1];
	wheel[wN][1] = temp;
}

void CounterClockwise(int wN)
{
	int temp = wheel[wN][0];
	wheel[wN][0] = wheel[wN][1];
	wheel[wN][1] = wheel[wN][2];
	wheel[wN][2] = wheel[wN][3];
	wheel[wN][3] = wheel[wN][4];
	wheel[wN][4] = wheel[wN][5];
	wheel[wN][5] = wheel[wN][6];
	wheel[wN][6] = wheel[wN][7];
	wheel[wN][7] = temp;
}

int main()
{

	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &wheel[i][j]);
		}
	}

	int k;
	cin >> k;
	
	for (int i = 0; i < k; i++)
	{
		int wheelNum, rotation;
		cin >> wheelNum >> rotation;

		if (wheelNum == 1)
		{
			if (wheel[1][2] != wheel[2][6])
			{
				if (wheel[2][2] != wheel[3][6])
				{
					if (wheel[3][2] != wheel[4][6])
					{
						if (rotation == 1)
						{
							CounterClockwise(4);
						}
						else
						{
							Clockwise(4);
						}
					}

					if (rotation == 1)
					{
						Clockwise(3);
					}
					else
					{
						CounterClockwise(3);
					}
				}
				
				if (rotation == 1)
				{
					CounterClockwise(2);
				}
				else
				{
					Clockwise(2);
				}
			}

			if (rotation == 1)
			{
				Clockwise(wheelNum);
			}
			else
			{
				CounterClockwise(wheelNum);
			}
		}
		else if (wheelNum == 2)
		{
			if (wheel[2][6] != wheel[1][2])
			{
				if (rotation == 1)
				{
					CounterClockwise(1);
				}
				else
				{
					Clockwise(1);
				}
			}

			if (wheel[2][2] != wheel[3][6])
			{
				if (wheel[3][2] != wheel[4][6])
				{
					if (rotation == 1)
					{
						Clockwise(4);
					}
					else
					{
						CounterClockwise(4);
					}
				}


				if (rotation == 1)
				{
					CounterClockwise(3);
				}
				else
				{
					Clockwise(3);
				}
			}

			if (rotation == 1)
			{
				Clockwise(wheelNum);
			}
			else
			{
				CounterClockwise(wheelNum);
			}
		}
		else if (wheelNum == 3)
		{
			if (wheel[3][6] != wheel[2][2])
			{
				if (wheel[2][6] != wheel[1][2])
				{
					if (rotation == 1)
					{
						Clockwise(1);
					}
					else
					{
						CounterClockwise(1);
					}
				}

				if (rotation == 1)
				{
					CounterClockwise(2);
				}
				else
				{
					Clockwise(2);
				}
			}


			if (wheel[3][2] != wheel[4][6])
			{
				if (rotation == 1)
				{
					CounterClockwise(4);
				}
				else
				{
					Clockwise(4);
				}
			}


			if (rotation == 1)
			{
				Clockwise(wheelNum);
			}
			else
			{
				CounterClockwise(wheelNum);
			}
		}
		else if (wheelNum == 4)
		{
			if (wheel[4][6] != wheel[3][2])
			{
				if (wheel[3][6] != wheel[2][2])
				{
					if (wheel[2][6] != wheel[1][2])
					{
						if (rotation == 1)
						{
							CounterClockwise(1);
						}
						else
						{
							Clockwise(1);
						}
					}

					if (rotation == 1)
					{
						Clockwise(2);
					}
					else
					{
						CounterClockwise(2);
					}
				}

				if (rotation == 1)
				{
					CounterClockwise(3);
				}
				else
				{
					Clockwise(3);
				}
			}

			if (rotation == 1)
			{
				Clockwise(wheelNum);
			}
			else
			{
				CounterClockwise(wheelNum);
			}
		}

		/*
		for (int j = 1; j < 5; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				printf("%d ", wheel[j][k]);
			}
			printf("\n");
		}
		*/
	}

	int result = 0;
	if (wheel[1][0] == 1)
	{
		result += 1;
	}

	if (wheel[2][0] == 1)
	{
		result += 2;
	}

	if (wheel[3][0] == 1)
	{
		result += 4;
	}

	if (wheel[4][0] == 1)
	{
		result += 8;
	}

	printf("%d\n", result);
}