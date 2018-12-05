#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[1001] = {0, };

    for (int i = 2; i <= 1000; i++){
        for (int j = 1; j <= 1000/i; j++){
            arr[j*i]++;
        }
    }

    int input[100];
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++){
        if (arr[input[i]] == 1)
            result++;
    }

    cout << result << endl;
}

