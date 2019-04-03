#include <iostream>

using namespace std;

char str[20];
int operArr[9] = { 1, 3, 5, 7, 9, 11, 13, 15, 17 };
int maxT = -2000000000;

int n;

void Combination(int start, int end, int idx, int need, int *arr)
{
	if (idx == need)
	{
		int numTemp[20];
		int numNum = 0;

		char operTemp[20];
		int operNum = 0;

		//printf("idx:%d need:%d\n", idx, need);

		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				numTemp[numNum++] = str[i] - '0';
			}
			else
			{
				operTemp[operNum++] = str[i];
			}
		}

		//printf("numNum:%d operNUm:%d\n", numNum, operNum);

		for (int i = 0; i < idx; i++)
		{
			int temp = arr[i];

			int sum;
			if (str[temp] == '+')
			{
				sum = (str[temp - 1] - '0') + (str[temp + 1] - '0');
			}
			else if (str[temp] == '-')
			{
				sum = (str[temp - 1] - '0') - (str[temp + 1] - '0');
			}
			else if (str[temp] == '/')
			{
				sum = (str[temp - 1] - '0') / (str[temp + 1] - '0');
			}
			else if (str[temp] == '*')
			{
				sum = (str[temp - 1] - '0') * (str[temp + 1] - '0');
			}

			numTemp[temp / 2] = sum;
			numTemp[temp / 2 + 1] = 0;
			operTemp[temp / 2] = '+';
		}

		int result = numTemp[0];

		for (int i = 0; i < operNum; i++)
		{
			char oT = operTemp[i];

			if (oT == '+')
			{
				result += numTemp[i + 1];
			}
			else if (oT == '-')
			{
				result -= numTemp[i + 1];
			}
			else if (oT == '/')
			{
				result /= numTemp[i + 1];
			}
			else if (oT == '*')
			{
				result *= numTemp[i + 1];
			}
		}
		
		//for (int i = 0; i < numNum; i++)
		//{
		//	printf("%d ", numTemp[i]);
		//}
		//printf("\n");

		//for (int i = 0; i < operNum; i++)
		//{
		//	printf("%d ", operTemp[i]);
		//}
		//printf("\n");

		//printf("result: %d\n", result);
		if (maxT < result)
		{
			maxT = result;
		}


		return;
	}
	else if (end - start < need - idx)
	{

		return;
	}
	else
	{
		arr[idx] = operArr[start];
		Combination(start + 2, end, idx + 1, need, arr);
		Combination(start + 1, end, idx, need, arr);
	}
}

int main()
{
	cin >> n >> str;

	int combArr[9] = { 0, };

	for (int i = 0; i <= (n / 2) / 2; i++)
	{ 
		Combination(0, n / 2, 0, i, combArr);
	}

	printf("%d\n", maxT);
}