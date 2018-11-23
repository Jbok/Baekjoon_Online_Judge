#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int k;
    cin >> k;

    int* inequality = new int[k];
    for (int i = 0; i < k; i++){
        cin >> inequality[i];
    }

    int* arr = new int[k+1];

    int min = pow(10, k+1);
    char* min
    int max = 0;

    for (int i = 0; i < pow(10, k+1); i++){
        int temp = i;
        int* flag = new int[k+1];



        for(int j = k; j >= 0; j--){
            arr[j] = temp / (pow(10, j) + 0.5);
            temp = temp - arr[j] * (pow(10, j) + 0.5);
            
            flag[arr[j]] = 1;
        }

        int possible = 1;

        for(int j = 0; j < k+1; j++){
            if (flag[j] != 1){
                possible = 0;
                break;
            }
        }

        if (possible == 0){
            if (i> max)
                max = i;
            else
                min = i;
            
        }

        delete[] flag;
    }

    delete[] inequality;
    delete[] arr;

}

