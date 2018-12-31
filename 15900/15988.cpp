#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;
    
    long long arr[1000001] = { 0, };

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for(int i = 4; i < 1000001; i++){
        arr[i] = (arr[i-1] + arr[i-2] + arr[i-3]) % 1000000009;
    }

    for (int i = 0; i < t; i++){
        int temp; 
        cin >> temp;
        cout << arr[temp] << endl;
    }
}
