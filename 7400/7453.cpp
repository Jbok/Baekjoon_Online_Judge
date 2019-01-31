#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long arr[4000] = { 0, };
long long brr[4000] = { 0, };
long long crr[4000] = { 0, };
long long drr[4000] = { 0, };

long long arr1[16000005] = { 0, };
long long arr2[16000005] = { 0, };

int LowerBound(long long arr[], int target, int size)
{
    int mid, start, end;
    start = 0;
    end = size - 1;

    while (end > start)
    {
        mid = (start + end) / 2;
        if (arr[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }

    return end;
}

int UpperBound(long long arr[], int target, int size)
{
    int mid, start, end;
    start = 0;
    end = size - 1;

    while (end > start)
    {
        mid = (start + end) / 2;
        if (arr[mid] > target)
            end = mid;
        else
            start = mid + 1;
    }

    return end;
}

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

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr1[cnt] = arr[i] + brr[j];
            arr2[cnt++] = crr[i] + drr[j];
        }
    }

    sort(arr1, arr1 + cnt);
    sort(arr2, arr2 + cnt);

    long long result = 0;
    int arr2_cnt = cnt - 1;
    int before = 0;
    int beforeTarget = 0;

    for (int i = 0; i < cnt; i++)
    {
        int target = arr1[i] * -1;


        if ( i != 0 )
        {
            if (beforeTarget == target)
            {
                result += before;
            }
            else
            {
                int temp = 0;
                while (1)
                {
                    if (arr2_cnt < 0)
                        break;

                    int target2 = arr2[arr2_cnt];

                    if (target2 < target)
                        break;

                    else if (target2 == target)
                    {
                        temp++;
                        arr2_cnt--;
                    }
                    else if (target2 > target)
                    {
                        arr2_cnt--;
                    }
                }    
                result += temp;
                before = temp;
                beforeTarget = target;   
            }

        }
        else
        {
            int temp = 0;
            while (1)
            {
                if (arr2_cnt < 0)
                    break;

                int target2 = arr2[arr2_cnt];

                if (target2 < target)
                    break;

                else if (target2 == target)
                {
                    temp++;
                    arr2_cnt--;
                }
                else if (target2 > target)
                {
                    arr2_cnt--;
                }
            }    
            result += temp;
            before = temp;
            beforeTarget = target;
        }
        
    }

    printf("%ld\n", result);
}