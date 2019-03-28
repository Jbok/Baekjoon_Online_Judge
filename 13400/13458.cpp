#include <iostream>

using namespace std;

int arr[1000000] = { 0, };

int main()
{
	int n;
	cin >> n;

	long long result = n;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int b, c;
	cin >> b >> c;

	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i] - b;
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			if (arr[i] % c == 0)
				result += arr[i] / c;
			else
				result += (arr[i] / c) + 1;
		}
	}

	printf("%ld\n", result);
}
