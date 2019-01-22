#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t, n, m;

    cin >> t >> n;

    int a[1001] = { 0, };

    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    cin >> m;
    int b[1001] = { 0, };
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    
    map<long long, long long> m1;

    int lengthA = 0;
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];

            if (m1.find(sum) == m1.end())
            {
                m1.insert(make_pair(sum, 1));
            }
            else
            {
                m1[sum] = m1[sum] + 1;
            }
        }
    }


    long long result = 0;

    int lengthB = 0;
    for (int i = 0; i < m; i++)
    {
        long long sum = 0;
        for (int j = i; j < m; j++)
        {
            sum += b[j];
            
            if (m1.find(t-sum) != m1.end())
            {
                result += m1[t-sum];
            }
        }
    }


    printf("%ld\n", result);
}