#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int sum = 0;

    for (int i = 0; i < t; i++)
    {
        sum = 0;

        int arr[100000][2] = { {0, }, };
        int max[100000][2] = { {0, }, };

        int n;
        cin >> n;

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> arr[k][j];
            }
        }
    
        for (int j = 0; j < n; j++)
        {
            int t1, t2, t3, t4;
            max[j][1] = max[j-2][0] + arr[j][1];
            max[j][0] = max[j-2][1] + arr[j][0];
            
            t3 = max[j-1][0] + arr[j][1];
            if (t3 > max[j][1])
                max[j][1] = t3;

            t4 = max[j-1][1] + arr[j][0];
            if (t4 > max[j][0])
                max[j][0] = t4;
        }

        int result;
        if (max[n-1][0] > max[n-1][1])
            result = max[n-1][0];
        else
            result = max[n-1][1];

        cout << result << endl;
    }

    

}
