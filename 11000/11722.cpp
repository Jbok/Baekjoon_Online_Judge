#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[1001];
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int temp[1000];
    int value = 0;

    for (int i = 1; i <= n; i++){

        for (int j=0; j <= value; j++){
            if (temp[j] <= arr[i]){
                temp[j] = arr[i];
                break;
            }

            if (j == value){
                value = value + 1;
                temp[value] = arr[i];
            }
        }
    }

    cout << value+1 << endl;
}
