#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    
    int arr[500][500];

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    int sum[500][500] = {0, };
    sum[0][0] = arr[0][0];
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= i; j++){
            int large;

            if (j == 0)
                large = sum[i-1][j];
            else if (j == i)
                large = sum[i-1][j-1];
            else
                large = sum[i-1][j] > sum[i-1][j-1] ? sum[i-1][j] : sum[i-1][j-1];
            
            sum[i][j] = arr[i][j] + large;
        }
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        result = sum[n-1][i] > result ? sum[n-1][i] : result;
    }

    cout << result << endl;
}
