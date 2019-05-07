#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int n;
int arr[20][20] = { 0, };
int maxValue = 0;

void Up(int resultArr[][20])
{
	for (int i = 0; i < n; i++)
	{
		deque<int> dq;
		deque<int> destDq;

		for (int j = 0; j < n; j++)
		{
			if (resultArr[j][i] != 0)
			{
				dq.push_back(resultArr[j][i]);
			}
		}

		for (deque<int>::iterator iter = dq.begin(); iter != dq.end(); iter++)
		{
			if ((iter +1) != dq.end() && *iter == *(iter + 1))
			{
				destDq.push_back((*iter) * 2);
				iter++;
			}
			else
			{
				destDq.push_back((*iter));
			}
		}

		int idx = 0;
		for (deque<int>::iterator iter = destDq.begin(); iter != destDq.end(); iter++)
		{
			resultArr[idx++][i] = (*iter);
		}
		for (int j = idx; j < n; j++)
		{
			resultArr[j][i] = 0;
		}
	}
}

void Down(int resultArr[][20])
{
	for (int i = 0; i < n; i++)
	{
		deque<int> dq;
		deque<int> destDq;

		for (int j = n-1; j >= 0; j--)
		{
			if (resultArr[j][i] != 0)
			{
				dq.push_back(resultArr[j][i]);
			}
		}

		for (deque<int>::iterator iter = dq.begin(); iter != dq.end(); iter++)
		{
			if ((iter + 1) != dq.end() && *iter == *(iter + 1))
			{
				destDq.push_back((*iter) * 2);
				iter++;
			}
			else
			{
				destDq.push_back((*iter));
			}
		}

		int idx = n-1;
		for (deque<int>::iterator iter = destDq.begin(); iter != destDq.end(); iter++)
		{
			resultArr[idx--][i] = (*iter);
		}
		for (int j = idx; j >= 0; j--)
		{
			resultArr[j][i] = 0;
		}
	}
}

void Right(int resultArr[][20])
{
	for (int i = 0; i < n; i++)
	{
		deque<int> dq;
		deque<int> destDq;

		for (int j = n - 1; j >= 0; j--)
		{
			if (resultArr[i][j] != 0)
			{
				dq.push_back(resultArr[i][j]);
			}
		}

		for (deque<int>::iterator iter = dq.begin(); iter != dq.end(); iter++)
		{
			if ((iter + 1) != dq.end() && *iter == *(iter + 1))
			{
				destDq.push_back((*iter) * 2);
				iter++;
			}
			else
			{
				destDq.push_back((*iter));
			}
		}

		int idx = n - 1;
		for (deque<int>::iterator iter = destDq.begin(); iter != destDq.end(); iter++)
		{
			resultArr[i][idx--] = (*iter);
		}
		for (int j = idx; j >= 0; j--)
		{
			resultArr[i][j] = 0;
		}
	}
}

void Left(int resultArr[][20])
{
	for (int i = 0; i < n; i++)
	{
		deque<int> dq;
		deque<int> destDq;

		for (int j = 0; j < n; j++)
		{
			if (resultArr[i][j] != 0)
			{
				dq.push_back(resultArr[i][j]);
			}
		}

		for (deque<int>::iterator iter = dq.begin(); iter != dq.end(); iter++)
		{
			if ((iter + 1) != dq.end() && *iter == *(iter + 1))
			{
				destDq.push_back((*iter) * 2);
				iter++;
			}
			else
			{
				destDq.push_back((*iter));
			}
		}

		int idx = 0;
		for (deque<int>::iterator iter = destDq.begin(); iter != destDq.end(); iter++)
		{
			resultArr[i][idx++] = (*iter);
		}
		for (int j = idx; j < n; j++)
		{
			resultArr[i][j] = 0;
		}
	}
}

void Combination(int now, int end, int *tArr)
{
	if (now == end)
	{
		int resultArr[20][20] = { 0, };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				resultArr[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (tArr[i] == 0)
			{
				Up(resultArr);
			}
			else if (tArr[i] == 1)
			{
				Down(resultArr);
			}
			else if (tArr[i] == 2)
			{
				Right(resultArr);
			}
			else if (tArr[i] == 3)
			{
				Left(resultArr);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (resultArr[i][j] > maxValue)
				{
					maxValue = resultArr[i][j];
				}
			}
		}
		
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			tArr[now] = i;
			Combination(now + 1, end, tArr);
		}
	}
	
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	
	int tArr[5] = { 0, };
	Combination(0, 5, tArr);
	
	printf("%d\n", maxValue);
}