#include <iostream>
#include <cstdio>

using namespace std;

long long combination[31][31] = { 0, };

int main()
{
	
	combination[1][0] = 1;
	combination[1][1] = 1;
	for (int i = 1; i <= 30; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				combination[i][j] = 1;
			}
			else
			{
				combination[i][j] = combination[i - 1][j] + combination[i - 1][j - 1];
			}
		}
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		printf("%lld\n", combination[b][a]);
	}
}