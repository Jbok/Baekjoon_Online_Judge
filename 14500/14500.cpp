#include <iostream>

using namespace std;

int arr[500][500] = { 0, };
int n, m;


int Figure1(int x, int y)
{
	int result = 0;

	if (x + 3 < m)
	{
		result = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure2(int x, int y)
{
	int result = 0;

	if (y + 3 < n)
	{
		result = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure3(int x, int y)
{
	int result = 0;

	if (y + 1 < n && x + 1 < m)
	{
		result = arr[y][x] + arr[y + 1][x] + arr[y][x + 1] + arr[y + 1][x+1];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure4(int x, int y)
{
	int result = 0;

	if (y + 2 < n && x + 1 < m)
	{
		result = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x + 1];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure5(int x, int y)
{
	int result = 0;

	if (y + 1 < n && x + 2 < m)
	{
		result = arr[y][x] + arr[y + 1][x] + arr[y][x + 1] + arr[y][x + 2];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure6(int x, int y)
{
	int result = 0;

	if (y + 2 < n && x + 1 < m)
	{
		result = arr[y][x] + arr[y + 1][x + 1] + arr[y + 2][x + 1] + arr[y][x + 1];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure7(int x, int y)
{
	int result = 0;

	if (y - 1 >= 0 && x + 2 < m)
	{
		result = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 2];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure8(int x, int y)
{
	int result = 0;

	if (y + 2 < n && x - 1 >= 0)
	{
		result = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x - 1];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure9(int x, int y)
{
	int result = 0;

	if (y + 1 < n && x + 2 < m)
	{
		result = arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 1][x + 2];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure10(int x, int y)
{
	int result = 0;

	if (y + 2 < n && x + 1 < m)
	{
		result = arr[y][x] + arr[y][x + 1] + arr[y + 1][x] + arr[y + 2][x];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure11(int x, int y)
{
	int result = 0;

	if (y + 1 < n && x + 2 < m)
	{
		result = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y+1][x+2];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure12(int x, int y)
{
	int result = 0;

	if (y + 2 < n && x + 1 < m)
	{
		result = arr[y][x] + arr[y+1][x] + arr[y+1][x+1] + arr[y+2][x+1];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure13(int x, int y)
{
	int result = 0;

	if (y - 1 >= 0 && x + 2 < m)
	{
		result = arr[y][x] + arr[y][x+1] + arr[y-1][x+1] + arr[y-1][x+2];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure14(int x, int y)
{
	int result = 0;

	if (y + 1 < n && x + 2 < m)
	{
		result = arr[y][x] + arr[y][x+1] + arr[y+1][x+1] + arr[y+1][x+2];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure15(int x, int y)
{
	int result = 0;

	if (y - 2 >= 0 && x + 1 < m)
	{
		result = arr[y][x] + arr[y-1][x] + arr[y-1][x+1] + arr[y-2][x+1];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure16(int x, int y)
{
	int result = 0;

	if (y - 1 >= 0 && x + 2 < m)
	{
		result = arr[y][x] + arr[y][x+1] + arr[y-1][x+1] + arr[y][x+2];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure17(int x, int y)
{
	int result = 0;

	if (y + 2 < n && x + 1 < m)
	{
		result = arr[y][x] + arr[y+1][x] + arr[y+1][x+1] + arr[y+2][x];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure18(int x, int y)
{
	int result = 0;

	if (y + 1 < n && x + 2 < m)
	{
		result = arr[y][x] + arr[y][x+1] + arr[y+1][x+1] + arr[y][x+2];
	}
	else
	{
		result = -1;
	}

	return result;
}

int Figure19(int x, int y)
{
	int result = 0;

	if (y + 2 < n && x - 1 >= 0)
	{
		result = arr[y][x] + arr[y+1][x] + arr[y+1][x-1] + arr[y+2][x];
	}
	else
	{
		result = -1;
	}

	return result;
}


int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (max < Figure1(j, i))
				max = Figure1(j, i);

			if (max < Figure2(j, i))
				max = Figure2(j, i);

			if (max < Figure3(j, i))
				max = Figure3(j, i);

			if (max < Figure4(j, i))
				max = Figure4(j, i);

			if (max < Figure5(j, i))
				max = Figure5(j, i);

			if (max < Figure6(j, i))
				max = Figure6(j, i);

			if (max < Figure7(j, i))
				max = Figure7(j, i);

			if (max < Figure8(j, i))
				max = Figure8(j, i);

			if (max < Figure9(j, i))
				max = Figure9(j, i);

			if (max < Figure10(j, i))
				max = Figure10(j, i);

			if (max < Figure11(j, i))
				max = Figure11(j, i);

			if (max < Figure12(j, i))
				max = Figure12(j, i);

			if (max < Figure13(j, i))
				max = Figure13(j, i);

			if (max < Figure14(j, i))
				max = Figure14(j, i);

			if (max < Figure15(j, i))
				max = Figure15(j, i);

			if (max < Figure16(j, i))
				max = Figure16(j, i);

			if (max < Figure17(j, i))
				max = Figure17(j, i);

			if (max < Figure18(j, i))
				max = Figure18(j, i);

			if (max < Figure19(j, i))
				max = Figure19(j, i);

		}
	}

	printf("%d\n", max);
}