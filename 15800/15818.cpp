#include <iostream>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;


    int arr[100];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long result = 1;

    for (int i = 0; i < n; i++){
        result *= arr[i] % m;
        result = result % m;
    }

    cout << result;
}
