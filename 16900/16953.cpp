#include <iostream>
#include <cstdio>

using namespace std;

int minNum = 2147483645;

void dfs(long long a, long long b, int num)
{
	if (a > b)
	{
		return;
	}
	else if (a == b)
	{
		if (num < minNum)
		{
			minNum = num;
		}
		return;
	}
	else
	{
		dfs(10 * a + 1, b, num + 1);
		dfs(2 * a, b, num + 1);
	}
	
}

int main()
{
	int a, b;
	cin >> a >> b;

	dfs(a, b, 0);

	if (minNum == 2147483645)
	{
		minNum = -1;
	}
	else
	{
		minNum += 1;
	}

	printf("%d\n", minNum);
}