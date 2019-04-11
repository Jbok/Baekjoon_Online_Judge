#include <iostream>
#include <string.h>

using namespace std;

char str[4];
char temp[4];

int result = 0;

void Permutation(int idx, int end)
{
	if (idx == end)
	{
		
		for (int i = 0; i < end-1; i++)
		{
			if (temp[i] == temp[i + 1])
			{
				return;
			}
		
		}
		result++;
		
		
		
		return;
	}
	else
	{
		if (str[idx] == 'd')
		{
			for (int i = 0; i < 10; i++)
			{
				temp[idx] = '0' + i;
				Permutation(idx + 1, end);
			}
		}
		else if (str[idx] == 'c')
		{
			for (int i = 0; i < 26; i++)
			{
				temp[idx] = 'a' + i;
				Permutation(idx + 1, end);
			}
		}
	}
}


int main()
{
	cin >> str;
	
	int length = strlen(str);

	Permutation(0, length);

	printf("%d\n", result);
}