#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
	int a;
	int b;
	int c;
}Node;

int map[101][101];
int result = 0;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char temp;
			scanf("%1c", &temp);

			if (temp == '\n')
				scanf("%1c", &temp);

			if (temp == '.')
			{
				map[i][j] = 0;
			}
			else
			{
				map[i][j] = 1;
			}
		}
	}

	deque<Node> dq;

	int tMap[101][101] = { 0, };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
			{
				int multiV = 1;

				while (1)
				{
					int nextLeft = j + multiV * -1;
					int nextRight = j + multiV * 1;
					int nextUp = i + multiV * -1;
					int nextDown = i + multiV * 1;

					if (nextLeft >= 0 && nextRight < m && nextUp >= 0 && nextDown < n)
					{
						if (map[i][nextLeft] == 1 && map[i][nextRight] == 1 && map[nextUp][j] == 1 && map[nextDown][j] == 1)
						{
							tMap[i][j] = 1;
							tMap[i][nextLeft] = 1;
							tMap[i][nextRight] = 1;
							tMap[nextUp][j] = 1;
							tMap[nextDown][j] = 1;
							result++;
							dq.push_back({ i+1, j+1, multiV });
						}
						else
						{
							break;
						}
					}
					else
					{
						break;
					}

					multiV++;
				}				
			}


		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != tMap[i][j])
			{
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", result);
	for (deque<Node>::iterator iter = dq.begin(); iter != dq.end(); iter++)
	{
		printf("%d %d %d\n", (*iter).a, (*iter).b, (*iter).c);
	}

}