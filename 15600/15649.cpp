#include <iostream>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << arr[i] << ' ' << arr[j] << endl;
        }
    }

}
