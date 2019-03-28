#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
	int r;
	int c;
	int age;
}tree;

priority_queue<int, vector<int>, greater<int>> pq[11][11];

deque<tree> deadQ;
deque<tree> makeChildQ;

int ground[11][11];
int add[11][11];

tree t[1001];

int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1,-1},{1,0}, {1,1} };

int main()
{
	int n, m, k;

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ground[i][j] = 5;
			scanf("%d", &add[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int r, c, z;
		scanf("%d%d%d", &r, &c, &z);

		pq[r][c].push(z);
	}

	for (int aaage = 0; aaage < k; aaage++)
	{

		for (int season = 0; season < 4; season++)
		{

			if (season == 0)	//spring
			{
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						// 양분을 먹으면 땅의 양분이 사라진다 가장
						deque<int> dqT;
						
						while (1)
						{
							if (pq[i][j].empty())
								break;

							int nowA = pq[i][j].top();
							pq[i][j].pop();

							if (nowA > ground[i][j])
							{
								deadQ.push_back({ i, j, nowA });
							}
							else
							{
								ground[i][j] -= nowA;
								dqT.push_back(nowA + 1);

								if ((nowA+1) % 5 == 0)
								{
									makeChildQ.push_back({ i, j, nowA+1 });
								}
							}
						}

						while (1)
						{
							if (dqT.empty())
								break;

							int temp = dqT.front();
							dqT.pop_front();

							pq[i][j].push(temp);
						}
					}
				}
			}
			else if (season == 1)	//summer
			{
				while (1)
				{
					if (deadQ.empty())
						break;

					int r, c, age;
					
					tree temp = deadQ.front();
					deadQ.pop_front();

					r = temp.r;
					c = temp.c;
					age = temp.age;

					ground[r][c] += age / 2;
				}
			}
			else if (season == 2)	//fall
			{
				while (1)
				{
					if (makeChildQ.empty())
						break;

					int r, c;

					tree temp = makeChildQ.front();
					makeChildQ.pop_front();
					r = temp.r;
					c = temp.c;

					for (int i = 0; i < 8; i++)
					{
						int nextR = r + dir[i][0];
						int nextC = c + dir[i][1];

						if (nextR >= 1 && nextR <= n && nextC >= 1 && nextC <= n)
						{
							pq[nextR][nextC].push(1);
						}
					}

				}
			}
			else if (season == 3)	//winter
			{
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						ground[i][j] += add[i][j];
					}
				}
			}


		}

	}



	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			while (1)
			{
				if (pq[i][j].empty())
					break;

				pq[i][j].pop();
				result++;

			}
		}
	}

	printf("%d\n", result);

}