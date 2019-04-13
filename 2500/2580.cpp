#include <iostream>
#include <vector>

using namespace std;

int board[10][10] = { 0, };
int row[10][10];
int col[10][10];
int group[9][10];

vector<int> v;

int flag = 1;

void dfs(int idx)
{
	if (flag == 1)
	{
		if (idx == v.size())
		{
			for (int i = 1; i < 10; i++)
			{
				for (int j = 1; j < 10; j++)
				{
					printf("%d ", board[i][j]);
				}
				printf("\n");
			}
			flag = 0;
			return;
		}
		else
		{
			//printf("idx: %d \n", idx);
			int temp = v[idx];
			int tR = (temp-1) / 9  + 1;
			int tC = (temp-1) % 9 + 1;
			int tGroupNum = ((tR - 1) / 3) * 3 + (tC - 1) / 3;

			//printf("temp:%d tR:%d tC:%d tGroupNUm:%d\n", temp, tR, tC, tGroupNum);

			for (int i = 1; i <= 9; i++)
			{
				if (row[tR][i] == 0 && col[tC][i] == 0 && group[tGroupNum][i] == 0)
				{
					//printf("	i: %d\n", i);
					board[tR][tC] = i;
					row[tR][i] = 1;
					col[tC][i] = 1;
					group[tGroupNum][i] = 1;
					

					dfs(idx+1);

					board[tR][tC] = 0;
					row[tR][i] = 0;
					col[tC][i] = 0;
					group[tGroupNum][i] = 0;
				}
			}
		}
	}
}
	


int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			int temp;
			scanf("%d", &temp);

			if (temp == 0)
			{
				//printf("[i:%d , j:%d] value:%d \n", i, j, (i - 1) * 9 + j);
				v.push_back((i - 1) * 9 + j);
			}

			board[i][j] = temp;
			
			row[i][temp] = 1;
			col[j][temp] = 1;

			int groupNum = ((i - 1) / 3) * 3 + (j - 1) / 3;
			group[groupNum][temp] = 1;
		}
	}

	//printf("v.size():%d\n", v.size());

	dfs(0);


}