#include <iostream>

using namespace std;

char a[12][9];

void RotationRight(int r, int c)
{
	char temp = a[r][c];

	a[r][c] = a[r + 1][c];
	a[r + 1][c] = a[r + 2][c];
	a[r + 2][c] = a[r + 2][c + 1];
	a[r + 2][c + 1] = a[r + 2][c + 2];
	a[r + 2][c + 2] = a[r + 1][c + 2];
	a[r + 1][c + 2] = a[r][c + 2];
	a[r][c + 2] = a[r][c + 1];
	a[r][c + 1] = temp;
}

void RotationLeft(int r, int c)
{
	char temp = a[r][c];
	
	a[r][c] = a[r][c + 1];
	a[r][c + 1] = a[r][c + 2];
	a[r][c + 2] = a[r + 1][c + 2];
	a[r + 1][c + 2] = a[r + 2][c + 2];
	a[r + 2][c + 2] = a[r + 2][c + 1];
	a[r + 2][c + 1] = a[r + 2][c];
	a[r + 2][c] = a[r + 1][c];
	a[r + 1][c] = temp;
}

void Rotation(char c, char b)
{
	if (c == 'U' && b == '-') // U-
	{
		RotationRight(9, 3);
		RotationRight(9, 3);

		char t1 = a[0][3];
		char t2 = a[0][4];
		char t3 = a[0][5];

		a[0][3] = a[3][8];
		a[0][4] = a[4][8];
		a[0][5] = a[5][8];

		a[3][8] = a[8][5];
		a[4][8] = a[8][4];
		a[5][8] = a[8][3];

		a[8][5] = a[5][0];
		a[8][4] = a[4][0];
		a[8][3] = a[3][0];

		a[5][0] = t1;
		a[4][0] = t2;
		a[3][0] = t3;
	}
	else if (c == 'U' && b == '+')	// U+
	{
		RotationLeft(9, 3);
		RotationLeft(9, 3);

		char t1 = a[0][3];
		char t2 = a[0][4];
		char t3 = a[0][5];

		a[0][3] = a[5][0];
		a[0][4] = a[4][0];
		a[0][5] = a[3][0];

		a[5][0] = a[8][5];
		a[4][0] = a[8][4];
		a[3][0] = a[8][3];

		a[8][5] = a[3][8];
		a[8][4] = a[4][8];
		a[8][3] = a[5][8];

		a[3][8] = t1;
		a[4][8] = t2;
		a[5][8] = t3;
	}
	else if (c == 'D' && b == '-')	// D-
	{
		RotationRight(3, 3);
		RotationRight(3, 3);

		char t1 = a[2][5];
		char t2 = a[2][4];
		char t3 = a[2][3];

		a[2][5] = a[3][2];
		a[2][4] = a[4][2];
		a[2][3] = a[5][2];

		a[3][2] = a[6][3];
		a[4][2] = a[6][4];
		a[5][2] = a[6][5];

		a[6][3] = a[5][6];
		a[6][4] = a[4][6];
		a[6][5] = a[3][6];

		a[5][6] = t1;
		a[4][6] = t2;
		a[3][6] = t3;
	}
	else if (c == 'D' && b == '+')	// D+
	{
		RotationLeft(3, 3);
		RotationLeft(3, 3);

		char t1 = a[2][3];
		char t2 = a[2][4];
		char t3 = a[2][5];

		a[2][3] = a[3][6];
		a[2][4] = a[4][6];
		a[2][5] = a[5][6];

		a[3][6] = a[6][5];
		a[4][6] = a[6][4];
		a[5][6] = a[6][3];

		a[6][5] = a[5][2];
		a[6][4] = a[4][2];
		a[6][3] = a[3][2];

		a[5][2] = t1;
		a[4][2] = t2;
		a[3][2] = t3;
	}
	else if (c == 'F' && b == '-')	// F-
	{
		RotationRight(6, 3);
		RotationRight(6, 3);

		char t1 = a[9][3];
		char t2 = a[9][4];
		char t3 = a[9][5];

		a[9][3] = a[5][8];
		a[9][4] = a[5][7];
		a[9][5] = a[5][6];

		a[5][8] = a[5][5];
		a[5][7] = a[5][4];
		a[5][6] = a[5][3];

		a[5][5] = a[5][2];
		a[5][4] = a[5][1];
		a[5][3] = a[5][0];

		a[5][2] = t1;
		a[5][1] = t2;
		a[5][0] = t3;

	}
	else if (c == 'F' && b == '+')	// F+
	{
		RotationLeft(6, 3);
		RotationLeft(6, 3);

		char t1 = a[9][3];
		char t2 = a[9][4];
		char t3 = a[9][5];

		a[9][3] = a[5][2];
		a[9][4] = a[5][1];
		a[9][5] = a[5][0];

		a[5][2] = a[5][5];
		a[5][1] = a[5][4];
		a[5][0] = a[5][3];

		a[5][5] = a[5][8];
		a[5][4] = a[5][7];
		a[5][3] = a[5][6];

		a[5][8] = t1;
		a[5][7] = t2;
		a[5][6] = t3;
	}
	else if (c == 'R' && b == '+')	// R+
	{
		RotationLeft(3, 6);
		RotationLeft(3, 6);

		char t1 = a[9][5];
		char t2 = a[10][5];
		char t3 = a[11][5];

		a[9][5] = a[6][5];
		a[10][5] = a[7][5];
		a[11][5] = a[8][5];
		
		a[6][5] = a[3][5];
		a[7][5] = a[4][5];
		a[8][5] = a[5][5];

		a[3][5] = a[0][5];
		a[4][5] = a[1][5];
		a[5][5] = a[2][5];

		a[0][5] = t1;
		a[1][5] = t2;
		a[2][5] = t3;
	}
	else if (c == 'R' && b == '-')	// R-
	{
		RotationRight(3, 6);
		RotationRight(3, 6);

		char t1 = a[9][5];
		char t2 = a[10][5];
		char t3 = a[11][5];

		a[9][5] = a[0][5];
		a[10][5] = a[1][5];
		a[11][5] = a[2][5];

		a[0][5] = a[3][5];
		a[1][5] = a[4][5];
		a[2][5] = a[5][5];

		a[3][5] = a[6][5];
		a[4][5] = a[7][5];
		a[5][5] = a[8][5];

		a[6][5] = t1;
		a[7][5] = t2;
		a[8][5] = t3;
	}
	else if (c == 'L' && b == '+')	// L+
	{
		RotationLeft(3, 0);
		RotationLeft(3, 0);

		char t1 = a[9][3];
		char t2 = a[10][3];
		char t3 = a[11][3];

		a[9][3] = a[0][3];
		a[10][3] = a[1][3];
		a[11][3] = a[2][3];

		a[0][3] = a[3][3];
		a[1][3] = a[4][3];
		a[2][3] = a[5][3];

		a[3][3] = a[6][3];
		a[4][3] = a[7][3];
		a[5][3] = a[8][3];

		a[6][3] = t1;
		a[7][3] = t2;
		a[8][3] = t3;
	}
	else if (c == 'L' && b == '-')	// L-
	{
		RotationRight(3, 0);
		RotationRight(3, 0);

		char t1 = a[9][3];
		char t2 = a[10][3];
		char t3 = a[11][3];

		a[9][3] = a[6][3];
		a[10][3] = a[7][3];
		a[11][3] = a[8][3];

		a[6][3] = a[3][3];
		a[7][3] = a[4][3];
		a[8][3] = a[5][3];

		a[3][3] = a[0][3];
		a[4][3] = a[1][3];
		a[5][3] = a[2][3];

		a[0][3] = t1;
		a[1][3] = t2;
		a[2][3] = t3;
	}
	else if (c == 'B' && b == '+')	// B+
	{
		RotationLeft(0, 3);
		RotationLeft(0, 3);

		char t1 = a[11][5];
		char t2 = a[11][4];
		char t3 = a[11][3];

		a[11][5] = a[3][6];
		a[11][4] = a[3][7];
		a[11][3] = a[3][8];

		a[3][6] = a[3][3];
		a[3][7] = a[3][4];
		a[3][8] = a[3][5];

		a[3][3] = a[3][0];
		a[3][4] = a[3][1];
		a[3][5] = a[3][2];

		a[3][0] = t1;
		a[3][1] = t2;
		a[3][2] = t3;
	}
	else if (c == 'B' && b == '-')	// B-
	{
		RotationRight(0, 3);
		RotationRight(0, 3);
		
		char t1 = a[11][5];
		char t2 = a[11][4];
		char t3 = a[11][3];

		a[11][5] = a[3][0];
		a[11][4] = a[3][1];
		a[11][3] = a[3][2];

		a[3][0] = a[3][3];
		a[3][1] = a[3][4];
		a[3][2] = a[3][5];

		a[3][3] = a[3][6];
		a[3][4] = a[3][7];
		a[3][5] = a[3][8];

		a[3][6] = t1;
		a[3][7] = t2;
		a[3][8] = t3;
	}

}

void NewCube()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			a[i][j] = 'o';
		}
	}

	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = 'g';
		}
	}

	for (int i = 3; i < 6; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			a[i][j] = 'y';
		}
	}

	for (int i = 3; i < 6; i++)
	{
		for (int j = 6; j < 9; j++)
		{
			a[i][j] = 'b';
		}
	}

	for (int i = 6; i < 9; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			a[i][j] = 'r';
		}
	}

	for (int i = 9; i < 12; i++)
	{
		for (int j = 3; j < 6; j++)
		{
			a[i][j] = 'w';
		}
	}
}

int main()
{ 
	/*
	int aaa = 1;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			a[i][j] = aaa++;
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	
	NewCube();
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	
	Rotation('L', '+');

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	


	*/
	int t;
	cin >> t;

	int cnt = 0;
	while (1)
	{
		if (cnt == t)
		{
			break;
		}

		int n;
		cin >> n;
			
		NewCube();
	
		char str[1000][2];
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
			Rotation(str[i][0], str[i][1]);
		}



		for (int i = 3; i < 6; i++)
		{
			printf("%c", a[11][i]);
		}
		printf("\n");
		for (int i = 3; i < 6; i++)
		{
			printf("%c", a[10][i]);
		}
		printf("\n");
		for (int i = 3; i < 6; i++)
		{
			printf("%c", a[9][i]);
		}
		printf("\n");



		cnt++;
	}
	
}