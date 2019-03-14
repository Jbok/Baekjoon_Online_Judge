#include <iostream>
#include <queue>
#include <deque>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
deque<pair<int, int>> dq[1001];
bool check[1001];
int result = 0;

void prim(int n)
{
    check[n] = true;

    for (deque<pair<int, int>>::iterator iter = dq[n].begin(); iter != dq[n].end(); iter++)
    {
        if (!check[(*iter).second])
        {
            pq.push({(*iter).first, (*iter).second});
        }
    }

    while (!pq.empty())
    {
        pair<int, int> temp = pq.top();
        pq.pop();
        if (!check[temp.second])
        {
            result += temp.first;
            prim(temp.second);
            return;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        dq[a].push_back({c, b});
        dq[b].push_back({c, a});
    }

    prim(1);
    printf("%d\n", result);
}