#include <cstdio>
#include <iostream>

using namespace std;

// int arr[1001][4] = { 0, };

int main()
{
	int n;
	cin >> n;

	int maxResult = 0;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);

		int value;
		// 같은 눈이 4개가 나옴
		if (a == b && b == c && c == d)
		{
			value = 50000 + a * 5000;
		}
		else if (a == b && b == c)
		{
			value = 10000 + a * 1000;
		}
		else if (a == b && b == d)
		{
			value = 10000 + a * 1000;
		}
		else if (a == c && c == d)
		{
			value = 10000 + a * 1000;
		}
		else if (b == c && c == d)
		{
			value = 10000 + b * 1000;
		}
		else if (a == b && c == d)
		{
			value = 2000 + a * 500 + c * 500;
		}
		else if (a == c && b == d)
		{
			value = 2000 + a * 500 + b * 500;
		}
		else if (a == d && b == c)
		{
			value = 2000 + a * 500 + b * 500;
		}
		else if (a != b && a != c && a != d && b != c && b != d && c != d)
		{
			int tempMax = a;
			if (b > tempMax)
				tempMax = b;

			if (c > tempMax)
				tempMax = c;

			if (d > tempMax)
				tempMax = d;

			value = tempMax * 100;

		}
		else
		{
			if (a == b)
			{
				value = 1000 + a * 100;
			}
			else if (a == c)
			{
				value = 1000 + a * 100;
			}
			else if (a == d)
			{
				value = 1000 + a * 100;
			}
			else if (b == c)
			{
				value = 1000 + b * 100;
			}
			else if (b == d)
			{
				value = 1000 + b * 100;
			}
			else if (c == d)
			{
				value = 1000 + c * 100;
			}
		}
		
		if (value > maxResult)
		{
			maxResult = value;
		}
	}

	printf("%d\n", maxResult);


}