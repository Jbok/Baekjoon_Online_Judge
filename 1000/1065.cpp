#include <iostream>
#include <cstdio>

using namespace std;

int CheckNum(int num)
{
	if (num >= 1 && num <= 9)
	{
		return 1;
	}
	else
	{
		int tempNum = num;

		int last = tempNum % 10;
		tempNum = tempNum / 10;

		int now = tempNum % 10;
		tempNum = tempNum / 10;

		int lastDiff = now - last;
		last = now;

		int flag = 1;
		while (1)
		{
			if (tempNum == 0)
			{
				break;
			}
			else
			{
				now = tempNum % 10;
				int nowDiff = now - last;
				if (nowDiff == lastDiff)
				{
					last = now;
					lastDiff = nowDiff;
					tempNum = tempNum / 10;
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}

		if (flag == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

int main()
{
	int n;
	cin >> n;

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result += CheckNum(i);
	}

	printf("%d\n", result);
}