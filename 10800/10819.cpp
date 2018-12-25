#include <iostream>
#include <cmath>

using namespace std;

void permutation(int n, int depth, int arr[], int result[], int flag[], int* max){
    
    if (n == depth){
        int value = 0;

        for (int i = 0; i < n-1; i++){
            value += abs(result[i] - result[i+1]);
        }
        
        if (value > *max)
            *max = value;

        return;
    }

    for (int i = 0; i < n; i++){
        if (flag[i] == 0){
            result[depth] = arr[i];
            flag[i] = 1;
            permutation(n, depth+1, arr, result, flag, max);
            flag[i] = 0;
        }

    }


}

int main(){

    int n;
    cin >> n;

    int arr[8] = {0, };
    int result[8] = {0, };
    
    int max = 0;
    int *pmax = &max;

    int flag[8] = {0, };

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    permutation(n, 0, arr, result, flag, pmax);

    cout << max;
}

