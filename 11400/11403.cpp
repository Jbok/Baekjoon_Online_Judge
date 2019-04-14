#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int arr[101][101] = { 0, };
int result[101][101] = { 0, };

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int check[101] = { 0, };
		deque<int> dq;

		dq.push_back(i);

		while (1)
		{
			if (dq.empty())
			{
				break;
			}

			int now = dq.front();
			dq.pop_front();

			for (int j = 0; j < n; j++)
			{
				if (arr[now][j] == 1 && check[j] == 0)
				{
					check[j] = 1;
					dq.push_back(j);
					result[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}

