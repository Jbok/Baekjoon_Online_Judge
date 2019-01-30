#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int arr[4000] = { 0, };
int brr[4000] = { 0, };
int crr[4000] = { 0, };
int drr[4000] = { 0, };

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cin >> brr[i];
        cin >> crr[i];
        cin >> drr[i];
    }

    map<int, int> m1, m2;

    int temp = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp1 = arr[i] + brr[j];
            int temp2 = crr[i] + drr[j];

            int tempCnt;
            tempCnt = m1.count(temp1);
            if (tempCnt != 0)
            {
                m1[temp1] += 1;
            }
            else
            {
                m1.insert(make_pair(temp1, 1));
            }

            tempCnt = m2.count(temp2);
            if (tempCnt != 0)
            {
                m2[temp2] += 1;
            }
            else
            {
                m2.insert(make_pair(temp2, 1));
            }
        }
    }


    int result = 0;
    for (map<int, int>::iterator iter = m1.begin(); iter != m1.end(); iter++)
    {
        int target = iter->first;

        int tempCount = m2.count(target * -1);
        if (tempCount != 0)
        {
            result += iter->second * m2[target * -1];
        }

    }

    printf("%d\n", result);
}