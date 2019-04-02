#include <iostream>

using namespace std;

int jiwooArr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };



int arr[3][20] = { 0, };
int proper[10][10];

int n, k;
int flag = 0;


int RSP()
{ 
	int arrNum[3] = { 0, };
	int arrWin[3] = { 0, };

	for (int i = 0; i < n; i++)
	{
		arr[0][i] = jiwooArr[i];
	}

	int first = 0;
	int second = 1;

	while (1)
	{
		if (arrWin[0] == k)
		{
			return 1;
		}

		if (arrNum[0] == n || arrWin[1] == k || arrWin[2] == k)
		{
			return 0;
		}

		int firstDo = arr[first][arrNum[first]];
		
		int secondDo = arr[second][arrNum[second]];
		
		/*
		if (arr[0][0] == 3 && arr[0][1] == 1 && arr[0][2] == 2)
		{
			printf("	firstDo:%d first:%d arrNum[first]:%d\n", firstDo, first, arrNum[first]);
			printf("	secondDo:%d second:%d arrNum[second]:%d\n", secondDo, second, arrNum[second]);
		}
		*/
		
		int third;
		if ((first + second) == 1)
		{
			third = 2;
		}
		else if ((first + second) == 2)
		{
			third = 1;
		}
		else if ((first + second) == 3)
		{
			third = 0;
		}



		if (proper[firstDo][secondDo] == 2)	// first win
		{
			arrWin[first]++;
			arrNum[first]++;
			arrNum[second]++;
			
			second = third;
		}
		else if (proper[firstDo][secondDo] == 0)	//second win
		{
			arrWin[second]++;
			arrNum[first]++;
			arrNum[second]++;
			first = third;

		}
		else if (proper[firstDo][secondDo] == 1)	//drow second win
		{
			if (first > second)
			{
				arrWin[first]++;
				arrNum[first]++;
				arrNum[second]++;

				second = third;
			}
			else
			{
				arrWin[second]++;
				arrNum[first]++;
				arrNum[second]++;

				first = third;

			}

		}

	}
}

void permutation(int start, int end)
{
	if (flag == 0)
	{
		if (start == end)
		{
			if (RSP() == 1)
			{
				flag = 1;
			}

			return;
		}
		else
		{
			for (int i = start; i < end; i++)
			{
				int temp = jiwooArr[start];
				jiwooArr[start] = jiwooArr[i];
				jiwooArr[i] = temp;

				permutation(start + 1, end);

				temp = jiwooArr[start];
				jiwooArr[start] = jiwooArr[i];
				jiwooArr[i] = temp;
			}
		}
	}
	
}

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &proper[i][j]);
		}
	}

	for (int i = 0; i < 20; i++)
	{
		scanf("%d", &arr[1][i]);
	}

	for (int i = 0; i < 20; i++)
	{
		scanf("%d", &arr[2][i]);
	}

	permutation(0, n);

	if (flag == 1)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
}