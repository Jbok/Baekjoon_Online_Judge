#include <iostream>

using namespace std;

int main()
{
    int cNum;
    cin >> cNum;

    for (int i = 0; i < cNum; i++)
    {
        int m, n, xInput, yInput;
        cin >> m >> n >> xInput >> yInput;

        int result = xInput;

        while (1)
        {
            if (result > m*n)
            {
                printf("-1\n");
                break;
            }

            int tempM = result % m;
            if (tempM == 0)
                tempM = m;
            
            int tempN = result % n;
            if (tempN == 0)
                tempN = n;

            if (tempM == xInput)
            {
                if (tempN == yInput)
                {
                    printf("%d\n", result);
                    break;
                }
            }

            result = result + m;
        }
    }
}