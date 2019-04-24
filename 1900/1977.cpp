#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	long long result = 0;
	int min = 1000000;

	int m, n;
	cin >> m >> n;

	int idx = 1;
	int target = 1;

	while (1)
	{	
		target = idx * idx;
		if (target > n)
		{
			break;
		}
		else
		{
			if (target >= m)
			{
				if (min > target)
				{
					min = target;
				}
				
				result += target;
			}
			else
			{

			}
		}

		idx++;
	}

	if (result == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n%d\n", result, min);
	}
}