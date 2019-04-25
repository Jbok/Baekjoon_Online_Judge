#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[26] = { 0, };
int arr2[26] = { 0, };

bool Compare(int a, int b)
{
	return a > b;
}

int main()
{
	while (1)
	{
		char temp;
		scanf("%c", &temp);

		if (temp == '\n')
		{
			break;
		}

		int num;

		if (temp > 'Z')
		{
			num = temp - 'a';
		}
		else
		{
			num = temp - 'A';
		}

		arr[num]++;
		arr2[num]++;

	}

	int maxNum = 0;
	int maxFlag = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr2[i] > maxNum)
		{
			maxNum = arr2[i];
			maxFlag = i;
		}
	}

	sort(arr, arr + 26, Compare);
	if (arr[0] == arr[1])
	{
		printf("?\n");
	}
	else
	{
		printf("%c", maxFlag + 'A');
	}
}