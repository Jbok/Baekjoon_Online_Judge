#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

typedef struct node
{
    double x;
    double y;
}point;

point arr[101] = { 0, };
vector<pair<double, int>> v[101];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
bool visited[101];

double result = 0;

void prim(int n)
{
    visited[n] = true;

    for (vector<pair<double, int>>::iterator iter = v[n].begin(); iter != v[n].end(); iter++)
    {
        if (!visited[(*iter).second])
        {
            pq.push((*iter));
        }
    }

    while (1)
    {
        if (pq.empty())
            break;

        pair<double, int> temp = pq.top();
        pq.pop();

        if (!visited[temp.second])
        {
            result += temp.first;
            prim(temp.second);
            return;
        }
    }
}

double CalValue(double x1, double y1, double x2, double y2)
{
    double x = x1-x2;
    double y = y1-y2;

    double result = sqrt(x*x + y*y);
    return result;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &arr[i].x, &arr[i].y);
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            double temp = CalValue(arr[i].x, arr[i].y, arr[j].x, arr[j].y);
            v[i].push_back({ temp, j });
            v[j].push_back({ temp, i });
        }
    }

    prim(0);
    printf("%.2lf\n", result);
    
}