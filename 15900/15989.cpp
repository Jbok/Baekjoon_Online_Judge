#include <iostream>

using namespace std;

int dp[10001] = { 0, };

int main()
{
    int t;
    cin >> t;

    dp[0] = 0;
    dp[1] = 0;

    for (int i =2; i < 10001; i++)
    {
        dp[i] = dp[i-1]*2 + 1;
    }

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        
    }
}
