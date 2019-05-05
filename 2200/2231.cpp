#include <iostream>
#include <cstdio>

using namespace std;

int MakeFunction(int num)
{
	int temp = num;
	
	while (1)
	{
		if (temp == 0)
		{
			break;
		}
		else
		{
			num += temp % 10;
			temp = temp / 10;
		}
	}

	return num;
}

int main()
{
	int n;
	cin >> n;

	int flag = 0;

	for (int i = 1; i <= 1000000; i++)
	{
		int result = MakeFunction(i);
		if (result == n)
		{
			printf("%d\n", i);
			flag = 1;
			break;
		}
	}

	if (flag == 0)
	{
		printf("0\n");
	}

}