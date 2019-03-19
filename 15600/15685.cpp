#include <iostream>
#include <deque>

using namespace std;


int main()
{
	int cnt;
	cin >> cnt;

	int arr[101][101] = { 0, };

	int result = 0;

	for (int i = 0; i < cnt; i++)
	{
		int x, y, d, g;
		scanf("%d%d%d%d", &x, &y, &d, &g);

		deque<int> dq;
		dq.push_back(d);

		for (int generation = 0; generation < g; generation++)
		{
			deque<int> dqTemp;
			dqTemp.assign(dq.begin(), dq.end());


			while (1)
			{
				if (dqTemp.empty())
					break;

				int tempDir = dqTemp.back();
				dqTemp.pop_back();
				
				int nextDir;
				if (tempDir== 0)
				{
					nextDir = 1;
				}
				else if (tempDir == 1)
				{
					nextDir = 2;
				}
				else if (tempDir == 2)
				{
					nextDir = 3;
				}
				else if (tempDir == 3)
				{
					nextDir = 0;
				}
				else
				{
					printf("ERROR\n");
					return -1;
				}

				dq.push_back(nextDir);
			}
		}

		arr[y][x] = 1;

		while (1)
		{
			if (dq.empty())
				break;

			int dir = dq.front();
			dq.pop_front();

			if (dir == 0)
			{
				x += 1;
			}
			else if (dir == 1)
			{
				y -= 1;
			}
			else if (dir == 2)
			{
				x -= 1;
			}
			else if (dir == 3)
			{
				y += 1;
			}
			else
			{
				printf("ERROR\n");
				return -1;
			}

			arr[y][x] = 1;

		}

	}



	for (int tx = 0; tx < 100; tx++)
	{
		for (int ty = 0; ty < 100; ty++)
		{
			if (arr[ty][tx] == 1 && arr[ty + 1][tx] == 1 && arr[ty][tx + 1] == 1 && arr[ty + 1][tx + 1] == 1)
			{
				result++;
			}
		}
	}

	printf("%d\n", result);
}