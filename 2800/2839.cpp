#include <iostream>

using namespace std;

int arr[5001] = { 0, };

int main()
{

	for (int i = 0; i < 5001; i++)
	{
		arr[i] = -1;
	}

	arr[3] = 1;
	arr[5] = 1;

	for (int i = 6; i <= 5000; i++)
	{
		int temp3 = 10000;
		int temp5 = 10000;

		if (arr[i - 3] != -1)
		{
			temp3 = arr[i - 3] + 1;
		}
		
		if (arr[i - 5] != -1)
		{
			temp5 = arr[i - 5] + 1;
		}

		if (temp3 == 10000 && temp5 == 10000)
		{
			arr[i] = -1;
		}
		else
		{
			arr[i] = temp3 < temp5 ? temp3 : temp5;
		}

	}

	int n;
	cin >> n;
	printf("%d\n", arr[n]);
}