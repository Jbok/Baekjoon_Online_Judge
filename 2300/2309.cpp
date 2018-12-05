#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int arr[9];
    
    for (int i = 0; i < 9; i++){
        cin >> arr[i];
    }

    sort(arr, arr+9);

    int sum = 0;
    for (int i = 0; i < 9; i++){
        sum += arr[i];
    }
    
    int flag[2];
    for (int i = 0; i < 9; i++){
        for (int j = i+1; j < 9; j++){
            if (sum - arr[i] - arr[j] == 100){
                flag[0] = i;
                flag[1] = j;
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++){
        if (i != flag[0] && i != flag[1])
            cout << arr[i] << endl;
    }
    
}
