#include <iostream>
#include <string.h>

using namespace std;


int main()
{
	char str[27];
	int alphabet[27] = { 0, };

	cin >> str;

	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = 99;
	}

	for (int i = 0; i < strlen(str); i++)
	{
		int temp = str[i] - 'a';
		alphabet[temp] = i;
	}

	if (strlen(str) != 26)
	{
		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] == 99)
			{
				for (int j = 0; j < strlen(str); j++)
				{
					printf("%c", str[j]);
				}

				printf("%c\n", i + 'a');
				return 0;
			}
		}
	}

	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		int temp = str[i] - 'a';

		for (int j = temp; j < 26; j++)
		{
			if (alphabet[j] > alphabet[temp])
			{

				for (int k = 0; k < i; k++)
				{
					printf("%c", str[k]);
				}
				printf("%c", j+'a');
				return 0;
			}
		}
	}

	printf("-1");
	return 0;
}