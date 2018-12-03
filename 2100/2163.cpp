#include <iostream>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    int arr[301][301];

    for (int i = 1; i < 301; i++){
        arr[1][i] = i-1;
        arr[i][1] = i-1;
    }

    for (int i = 2; i < 301; i++){
        for (int j = i; j < 301; j++){
            if (i%2 == 0){
                arr[i][j] = arr[i/2][j] * 2 + 1;
                arr[j][i] = arr[i/2][j] * 2 + 1;
            }
            else
            {
                arr[i][j] = arr[i/2+1][j] + arr[i/2][j] + 1;
                arr[j][i] = arr[i/2+1][j] + arr[i/2][j] + 1;


            }
        }
    }

    cout << arr[n][m] << endl;

}
