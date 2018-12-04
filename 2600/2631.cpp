#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[200];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int temp[200] ={0, };
    int val = 0;
    for (int j = 0; j < n; j++){
        for (int k = 0; k <= val; k++){
            if (arr[j] <= temp[k]){
                temp[k] = arr[j];
                break;
            }

            if (k==val){
                val = val+1;
                temp[val] = arr[j];
            }
        }
    }

    cout << n - val << endl;
}
