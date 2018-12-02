#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;

    int arr0[101][100];
    int arr1[101][100];
    int inputN[1000];
    int inputK[1000];

    for(int i = 0; i < t; i++){
        cin >> inputN[i];
        cin >> inputK[i];
    }


    arr0[1][0] = 1;
    arr1[1][0] = 1;

    for (int i = 1; i < 100; i++){

        for (int j = 0; j < 99; j++){
            arr0[i+1][j] =  arr0[i][j] + arr1[i][j];
            if (j == 0)
                arr1[i+1][j] = arr0[i][j];
            else
                arr1[i+1][j] =  arr0[i][j] + arr1[i][j-1];
        }

    }
    int n, k;
    int result;
    for (int i = 0; i < t; i++){
        result = arr0[inputN[i]][inputK[i]] + arr1[inputN[i]][inputK[i]];
        cout << result << endl;
    }

}
