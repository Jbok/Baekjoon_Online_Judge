#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;

	vector<long long> v[60];

	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;

		long long t = temp;

		int cnt = 0;
		while (1)
		{
			if (t % 3 != 0)
			{
				break;
			}

			t /= 3;
			cnt++;
		}

		v[cnt].push_back(temp);
	}

	for (int i = 59; i >= 0; i--)
	{
		sort(v[i].begin(), v[i].end(), greater<long long>());
		while (1)
		{
			if (v[i].empty())
			{
				break;
			}

			printf("%lld ", v[i].back());
			v[i].pop_back();
		}
	}

	
	

}