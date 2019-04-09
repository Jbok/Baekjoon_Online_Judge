#include <iostream>
#include <deque>

using namespace std;

int ladder[101] = { 0, };
int check[101] = { 0, };

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 100; i++)
	{
		ladder[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		ladder[u] = v;
	}

	deque<pair<int, int>> dq;
	dq.push_back({ 1, 0 });

	while (1)
	{
		if (dq.empty())
		{
			break;
		}

		pair<int, int> now = dq.front();
		dq.pop_front();

		if (now.first == 100)
		{
			printf("%d\n", now.second);
			break;
		}

		for (int i = 1; i <= 6; i++)
		{	
			if (now.first + i <= 100 && check[now.first +i] == 0)
			{
				check[now.first + i] = 1;
				
				if (ladder[now.first + i] == (now.first + i))
				{
					dq.push_back({ now.first + i, now.second + 1 });
				}
				else if (check[ladder[now.first + i]] == 0)
				{
					check[ladder[now.first + i]] = 1;
					dq.push_back({ ladder[now.first + i], now.second + 1 });
				}		
			}
			else
			{

			}
		}
	}

}