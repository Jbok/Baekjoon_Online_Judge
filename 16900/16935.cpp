#include <iostream>
#include <deque>

using namespace std;

int arr[101][101];

int n, m, r;



void One()
{
	deque<int> dq;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dq.push_back(arr[i][j]);
		}
	}


	for (int i = n-1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			int temp = dq.front();
			dq.pop_front();

			arr[i][j] = temp;
		}
	}
}

void Two()
{
	deque<int> dq;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dq.push_back(arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = m-1; j >= 0; j--)
		{
			int temp = dq.front();
			dq.pop_front();

			arr[i][j] = temp;
		}
	}
}

void Three()
{
	deque<int> dq;

	for (int i = 0; i < m; i++)
	{
		for (int j = n-1; j >= 0; j--)
		{
			dq.push_back(arr[j][i]);
		}
	}

	int temp = n;
	n = m;
	m = temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = dq.front();
			dq.pop_front();
		}
	}
}

void Four()
{
	deque<int> dq;

	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			dq.push_back(arr[j][i]);
		}
	}

	int temp = n;
	n = m;
	m = temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = dq.front();
			dq.pop_front();
		}
	}
}

void Five()
{
	deque<int> firstDq;
	deque<int> secondDq;
	deque<int> thirdDq;
	deque<int> fourthDq;
	///////////////////////////////////////
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			int temp = arr[i][j];
			firstDq.push_back(temp);
		}
	}

	for (int i = n / 2; i < n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			int temp = arr[i][j];
			fourthDq.push_back(temp);
		}
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			int temp = arr[i][j];
			secondDq.push_back(temp);
		}
	}

	for (int i = n / 2; i < n; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			int temp = arr[i][j];
			thirdDq.push_back(temp);
		}
	}

	/////////////////////////////////////
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			int temp = fourthDq.front();
			fourthDq.pop_front();

			arr[i][j] = temp;
		}
	}

	for (int i = n / 2; i < n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			int temp = thirdDq.front();
			thirdDq.pop_front();

			arr[i][j] = temp;
		}
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			int temp = firstDq.front();
			firstDq.pop_front();

			arr[i][j] = temp;
		}
	}

	for (int i = n / 2; i < n; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			int temp = secondDq.front();
			secondDq.pop_front();

			arr[i][j] = temp;
		}
	}
}

void Six()
{
	deque<int> firstDq;
	deque<int> secondDq;
	deque<int> thirdDq;
	deque<int> fourthDq;

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			int temp = arr[i][j];
			firstDq.push_back(temp);
		}
	}

	for (int i = n/2; i < n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			int temp = arr[i][j];
			fourthDq.push_back(temp);
		}
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = m/2; j < m; j++)
		{
			int temp = arr[i][j];
			secondDq.push_back(temp);
		}
	}

	for (int i = n/2; i < n; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			int temp = arr[i][j];
			thirdDq.push_back(temp);
		}
	}


	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			int temp = secondDq.front();
			secondDq.pop_front();

			arr[i][j] = temp;
		}
	}

	for (int i = n / 2; i < n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			int temp = firstDq.front();
			firstDq.pop_front();

			arr[i][j] = temp;
		}
	}

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			int temp = thirdDq.front();
			thirdDq.pop_front();

			arr[i][j] = temp;
		}
	}

	for (int i = n / 2; i < n; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			int temp = fourthDq.front();
			fourthDq.pop_front();

			arr[i][j] = temp;
		}
	}
}

int main()
{
	
	cin >> n >> m >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < r; i++)
	{
		int temp;
		cin >> temp;
		
		if (temp == 1)
		{
			One();
		}
		else if (temp == 2)
		{
			Two();
		}
		else if (temp == 3)
		{
			Three();
		}
		else if (temp == 4)
		{
			Four();
		}
		else if (temp == 5)
		{
			Five();
		}
		else if (temp == 6)
		{
			Six();
		}
	}





	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}