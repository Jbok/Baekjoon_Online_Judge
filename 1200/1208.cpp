#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[40] = { 0, };
long long result = 0;

void combination(int n, int start, int depth, int end, long long sum, long long s, vector<long long> *v)
{
    if (depth == n)
    {
        // printf("sum:%d \n", sum);
        if (s == sum)
            result++;
        (*v).push_back(sum);
        return;
    }

    if (end - start < n - depth)
        return;

    for (int i = start; i < end; i++)
    {
        sum += arr[i];
        combination(n, i+1, depth+1, end, sum, s, v);
        sum -= arr[i];
    }
}

int main()
{
    int n;
    cin >> n;

    long long s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    vector<long long> v1, v2;
    vector<long long> *vp1 = &v1;
    vector<long long> *vp2 = &v2;
    
    for (int i = 1; i <= n/2; i++)
    {
        combination(i, 0, 0, n/2, 0, s, vp1);
    }

    for (int i = n/2 + 1; i <= n; i++)
    {
        combination(i, n/2, n/2, n, 0, s, vp2);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int beforeTarget = 0;
    long long beforeMatchNum = 0;

    int v2i = v2.size() - 1;
    
    for (int i = 0; i < v1.size(); i++)
    {
        int target = s - v1[i];
    
        if (i != 0 && beforeTarget == target)
        {
            result += beforeMatchNum;
        }
        else
        {
            long long matchNum = 0;
            while (1)
            {
                if (v2i < 0)
                    break;

                if (v2[v2i] < target)
                {
                    break;
                }
                else if (v2[v2i] == target)
                {
                    matchNum++;
                    v2i--;
                }
                else if (v2[v2i] > target)
                {
                    v2i--;
                }
            }
            result += matchNum;
            beforeTarget = target;
            beforeMatchNum = matchNum;
        }
    }

    printf("%lld\n", result);
}