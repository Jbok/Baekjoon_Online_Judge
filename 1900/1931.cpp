#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct
{
	int start;
	int end;
}Conference;

Conference arr[100000];

bool Compare(Conference a, Conference b)
{
	if (a.end == b.end)
	{
		return a.start < b.start;
	}
	else
	{
		return a.end < b.end;
	}
}

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		arr[i] = { a, b };
	}

	sort(arr, arr + n, Compare);

	int nowEnd = arr[0].end;
	int result = 1;

	for (int i = 1; i < n; i++)
	{
		if (arr[i].start >= nowEnd)
		{
			nowEnd = arr[i].end;
			result++;
		}
	}

	printf("%d\n", result);

}