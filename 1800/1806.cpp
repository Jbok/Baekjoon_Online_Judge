#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int arr[100001] = { 0, };

int main()
{
    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<int>());    

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum >= s){
            printf("%d\n", i+1);
            break;
        }
    }
    printf("0\n");
}