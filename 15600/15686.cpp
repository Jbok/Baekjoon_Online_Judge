#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
	int r;
	int c;
	int cnt;
}Node;

Node chicken[14];

int dir[4][2] = { { 1, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 } };

int mmin = 50 * 50 * 100;

int bfs(int r, int c, int n, int arr[50][50])
{
	int check[50][50] = { 0, };

	deque<Node> temp;
	temp.push_back({ r, c, 0 });
	check[r][c] = 1;


	while (1)
	{
		if (temp.empty())
			break;

		Node now = temp.front();
		temp.pop_front();

		if (arr[now.r][now.c] == 2)
		{
			return now.cnt;
		}

		for (int i = 0; i < 4; i++)
		{
			if (now.r + dir[i][0] >= 0 && now.r + dir[i][0] < n && now.c + dir[i][1] >= 0 && now.c + dir[i][1] < n)
			{
				if (check[now.r + dir[i][0]][now.c + dir[i][1]] == 0)
				{
					Node next = { now.r + dir[i][0], now.c + dir[i][1], now.cnt + 1 };
					temp.push_back(next);
					check[now.r + dir[i][0]][now.c + dir[i][1]] = 1;
				}
			}
		}

	}
}




void Combination(int nn, int n, int c, int target, int index, Node temp[], int arr[50][50])
{
	if (index == c)
	{
		for (int i = 0; i < c; i++)
		{			
			arr[temp[i].r][temp[i].c] = 0;
		}

		int result = 0;

		for (int i = 0; i < nn; i++)
		{
			for (int j = 0; j < nn; j++)
			{
				if (arr[i][j] == 1)
				{
					result += bfs(i, j, nn, arr);
				}
			}
		}

		if (result < mmin)
			mmin = result;


		for (int i = 0; i < c; i++)
		{
			arr[temp[i].r][temp[i].c] = 2;
		}
		return;
	}
	else if (c - index > n - target)
	{
		return;
	}
	else
	{
		Combination(nn, n, c, target + 1, index, temp, arr);

		temp[index] = chicken[target];
		Combination(nn, n, c, target + 1, index + 1, temp, arr);
	}
}



int main()
{
	int n, m;
	cin >> n >> m;

	int arr[50][50];

	int chickenNum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				chicken[chickenNum++] = { i, j };
			}
		}
	}

	Node temp[13] = { {0, }, };

	Combination(n, chickenNum, chickenNum - m, 0, 0, temp, arr);


	printf("%d\n", mmin);


}