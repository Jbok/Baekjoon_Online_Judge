#include <iostream>
#include <deque>

using namespace std;

typedef struct node1
{
	int time;
	char dir;
}info;

typedef struct node2
{
	int r;
	int c;
}point;

int arr[101][101] = { 0, };

char dir[100000];

int main()
{
	int result = 0;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;

		arr[r][c] = 1;
	}

	int l;
	cin >> l;

	info dirChange[100];
	for (int i = 0; i < l; i++)
	{
		//cin >> dirChange[i].time;
		int t;
		cin >> t;
		char temp;
		cin >> temp;

		dir[t] = temp;


	}


	deque<point> dq;
	dq.push_back({ 1,1 });

	int dirCnt = 0;
	int nowTime = dirChange[dirCnt].time;
	int nowDir = 1;
	int nowR = 1;
	int nowC = 1;
	
	while (1)
	{
		result++;

		int nextR = nowR;
		int nextC = nowC;

		if (nowDir == 0)
		{
			nextR = nowR - 1;
		}
		else if (nowDir == 1)
		{
			nextC = nowC + 1;
		}
		else if (nowDir == 2)
		{
			nextR = nowR + 1;
		}
		else if (nowDir == 3)
		{
			nextC = nowC - 1;
		}

		if (nextR < 1 || nextR > n || nextC < 1 || nextC > n)
		{
			break;
		}

		int flag = 1;
		for (deque<point>::iterator iter = dq.begin(); iter != dq.end(); iter++)
		{
			if ((*iter).c == nextC && (*iter).r == nextR)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			break;
		}

		/*
		printf("\n");
		for (deque<point>::iterator iter = dq.begin(); iter != dq.end(); iter++)
		{
			printf("[%d , %d]\n", (*iter).r, (*iter).c);
		}
		printf("\n");
		*/



		if (arr[nextR][nextC] == 1)
		{
			dq.push_back({ nextR, nextC });
			arr[nextR][nextC] = 0;
		}
		else
		{
			dq.push_back({ nextR, nextC });
			dq.pop_front();
		}

		if (dir[result] != 0)
		{
			char tempDir = dir[result];
			if (nowDir == 0 && tempDir == 'L')
			{
				nowDir = 3;
			}
			else if (nowDir == 0 && tempDir == 'D')
			{
				nowDir = 1;
			}
			else if (nowDir == 1 && tempDir == 'L')
			{
				nowDir = 0;
			}
			else if (nowDir == 1 && tempDir == 'D')
			{
				nowDir = 2;
			}
			else if (nowDir == 2 && tempDir == 'L')
			{
				nowDir = 1;
			}
			else if (nowDir == 2 && tempDir == 'D')
			{
				nowDir = 3;
			}
			else if (nowDir == 3 && tempDir == 'L')
			{
				nowDir = 2;
			}
			else if (nowDir == 3 && tempDir == 'D')
			{
				nowDir = 0;
			}
		}
		
		
		nowR = nextR;
		nowC = nextC;
	}



	printf("%d\n", result);
}