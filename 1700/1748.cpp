#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    long long result = 0;

    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (1)
        {
            if (temp == 0)
                break;
            
            result++;
            temp = temp / 10;
        }
    }

    printf("%d\n", result);

    return 0;
}