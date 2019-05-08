#include <iostream>
#include <cstdio>

using namespace std;

int arr[10001] = { 0, };

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);

		arr[temp]++;
	}

	for (int i = 0; i <= 10000; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			printf("%d\n", i);
		}
	}
}