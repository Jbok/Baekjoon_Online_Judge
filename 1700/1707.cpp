#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > v;
int check[20001] = { 0, };
int color[20001] = { 0, };
int flag = 0;

void dfs(int now)
{
    if (flag)
        return;
    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];
        if (check[next] == 0)
        {
            check[next] = 1;
            color[next] = color[now] * -1;
            dfs(next);
        }
        else if (color[next] == color[now])
            flag = 1;
    }
}

int main()
{
    int caseNum;
    cin >> caseNum;

    for (int cN = 0; cN < caseNum; cN++)
    {

        for (int i = 0; i < 20001; i++)
        {
            check[i] = 0;
            color[i] = 0;
        }

        int node, edge;
        cin >> node >> edge;
        v.clear();
        v.resize(node+1);

        flag = 0;

        int x, y;
        for (int eN = 0; eN < edge; eN++)
        {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for (int i = 1; i <= x; i++)
        {
            if (flag)
                break;
                
            if (!check[i])
            {
                check[i] = 1;
                color[i] = 1;
                dfs(i);
            }
        }
        
        if (flag)
            printf("NO\n");
        else
            printf("YES\n");

    }
}


/*
#include <iostream>
#include <deque>
#include <vector>

using namespace std;


int main()
{
	int k;
	cin >> k;
	for (int testCase = 0; testCase < k; testCase++)
	{
		int flag = 1;

		int v, e;
		scanf("%d", &v);
		scanf("%d", &e);

		vector<int> vect[20001];

		for (int i = 0; i < e; i++)
		{
			int a, b;
			scanf("%d", &a);
			scanf("%d", &b);

			vect[a].push_back(b);
			vect[b].push_back(a);
		}
		
		
		int check[20001] = { 0, };
		int color[20001] = { 0, };
		
		int startColor = 1;

		deque<pair<int, int>> dq;

		for (int i = 1; i <= v; i++)
		{
			if (check[i] == 1)
			{

			}
			else
			{

				dq.push_back({ i, startColor });

				check[i] = 1;
				color[1] = startColor;


				while (1)
				{
					if (dq.empty())
					{
						break;
					}

					pair<int, int> now = dq.front();
					int nowNode = dq.front().first;
					int nowColor = dq.front().second;
					dq.pop_front();
					//printf("nowNode:%d nowColor:%d \n", nowNode, nowColor);

					while (1)
					{
						if (vect[nowNode].empty())
						{
							break;
						}

						int nextNode = vect[nowNode].back();
						vect[nowNode].pop_back();

						//printf("	nextNode:%d  nextColor:%d \n", nextNode, nowColor*-1);

						if (check[nextNode] == 0)
						{
							check[nextNode] = 1;
							color[nextNode] = nowColor * -1;
							dq.push_back({ nextNode, nowColor*-1 });
						}
						else
						{
							if (color[nextNode] == nowColor)
							{
								flag = 0;
							}
						}
					}
				}


			}
		}

		


		if (flag == 0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}




	}
}

*/