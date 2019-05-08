#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n; 
	cin >> n;

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%1d", &temp);

		result += temp;
	}

	printf("%d\n", result);
}