#include <iostream>
#include <deque>

using namespace std;

int arr[100001] = { 0, };
int check[100001] = { 0, };

int main()
{
	int n, k;
	cin >> n >> k;

	deque<pair<int, int>> dq;
	dq.push_back({ n, 0 });

	check[n] = 1;

	while (1)
	{
		if (dq.empty())
			break;

		pair<int, int> Ptemp = dq.front();
		int temp = Ptemp.first;
		arr[temp] = Ptemp.second;

		dq.pop_front();

		for (int i = 0; i < 3; i++)
		{
			int next;
			if (i == 0)
			{
				next = temp - 1;
			}
			else if (i == 1)
			{
				next = temp + 1;
			}
			else
			{
				next = temp * 2;
			}

			if (next >= 0 && next <= 100000 && check[next] == 0)
			{
				check[next] = 1;
				dq.push_back({ next ,Ptemp.second + 1 });
			}
		}
	}

	printf("%d\n", arr[k]);
}