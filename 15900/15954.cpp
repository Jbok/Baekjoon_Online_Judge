#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    double arr[501] = { 0, };

    double min = 1000000.0;

    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &arr[i]);
    }

    for (int i = k; i <= n; i++)
    {
        for (int j = 1; j <= n-i+1; j++)
        {   
            double m = 0.0;
            for (int l = j; l < j+i; l++)
            {
            
                m = m + arr[l];
            
            }
            
            m = m / i;

            double variance = 0;
            for (int l = j; l < j+i; l++)
            {
                variance += (arr[l] - m) * (arr[l] - m);
            }
            variance = variance / i;

            double std = sqrt(variance);
            if (std < min)
                min = std;

        }
    }

    printf("%lf", min);

    return 0;
}