#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    long long result;
    result = a%b;

    if (result == 0)
        return b;
    else
        gcd(b, result);
}

int main(){

    int t;
    cin >> t;

    int arr[101][101] = {0, };

    for (int i = 0; i < t; i++){
        cin >> arr[i][0];
        for (int j = 1; j <= arr[i][0]; j++){
            cin >> arr[i][j];
        }
    }

    long long result[100] = {0, };

    for (int i = 0; i < t; i++){
        if (arr[i][0] == 1)
            result[i] = arr[i][1];
        for (int j = 1; j < arr[i][0]; j++){
            for (int k = j+1; k <= arr[i][0]; k++){
                int large = arr[i][j] > arr[i][k] ? arr[i][j] : arr[i][k];
                int small = arr[i][j] < arr[i][k] ? arr[i][j] : arr[i][k];
                result[i] += gcd(large, small);
            }
        }
    }

    for (int i = 0; i < t; i++){
        cout << result[i] << endl;
    }

}
