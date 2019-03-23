//#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

typedef struct node
{
	int r;
	int c;
	int cnt;
}Node;

Node chicken[14];

int dir[4][2] = { { 1, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 } };

Node home[100];
int homeNum = 0;

int mmin = 50 * 50 * 100;

void Combination(int nn, int n, int c, int target, int index, Node temp[])
{
	if (index == c)
	{
		int result = 0;

		for (int i = 0; i < homeNum; i++)
		{
			int resultTemp = 50*50*1000;

			for (int j = 0; j < c; j++)
			{
				int tempR = abs(temp[j].r - home[i].r);
				
				int tempC = abs(temp[j].c - home[i].c);
				

				if (resultTemp > (tempR + tempC))
					resultTemp = (tempR + tempC);
				
			}

			result += resultTemp;
		}

		if (result < mmin)
			mmin = result;
					

		return;
	
	}
	else if (c - index > n - target)
	{
		return;
	}
	else
	{
		Combination(nn, n, c, target + 1, index, temp);

		temp[index] = chicken[target];
		Combination(nn, n, c, target + 1, index + 1, temp);
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
			else if (arr[i][j] == 1)
			{
				home[homeNum++] = { i, j };
			}
		}
	}

	Node temp[13] = { {0, }, };

	Combination(n, chickenNum, m, 0, 0, temp);


	printf("%d\n", mmin);


}