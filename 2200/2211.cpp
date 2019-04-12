#include <iostream>
#include <queue>

#define INF 2147483647

using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;


int arr[1001][1001];
int visit[1001] = { 0, };

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}

	printf("%d\n", n - 1);

	for (int i = 1; i <= n; i++)
	{
		int weight = arr[1][i];
		if (weight < INF)
		{
			pq.push({ weight, {1, i} });
		}
	}
	visit[1] = 1;

	while (1)
	{
		if (pq.empty())
		{
			break;
		}

		pair<int, pair<int, int>> now = pq.top();
		pq.pop();

		int nowNode = now.second.first;
		int nextNode = now.second.second;
		int nowWeight = now.first;
		
		if (visit[nextNode] == 0)
		{
			printf("%d %d\n", nowNode, nextNode);

			for (int tempNode = 1; tempNode <= n; tempNode++)
			{
				if (visit[tempNode] == 0)
				{
					int prevW = arr[nextNode][tempNode];
					if (prevW < INF)
					{
						pq.push({ nowWeight + prevW,{nextNode, tempNode} });
					}
					else
					{

					}
				}
			}
			visit[nextNode] = 1;
		}
		else
		{

		}
	}


	
}