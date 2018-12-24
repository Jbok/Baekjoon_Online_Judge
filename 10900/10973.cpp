#include <iostream>

using namespace std;

int main(){

    int n;

    scanf("%d", &n);

    int *arr = new int[n];

    for (int i = 0; i < n; i++){

        scanf("%d", &arr[i]);

    }

    bool flag = false;

    for (int i = n-1; i > 0; i--){

        if (arr[i] < arr[i-1]){
            flag = true;
            for (int j = n-1; j >= i; j--){
                if (arr[j] < arr[i-1]){
                    int temp = arr[j];
                    arr[j] = arr[i-1];
                    arr[i-1] = temp;
                    break;
                }
            }

            for (int k = n-1; k > i; k--){
                for (int p = k-1 ; p >= i; p--){
                    if (arr[k] > arr[p]){
                        int temp = arr[k];
                        arr[k] = arr[p];
                        arr[p] = temp;
                    }
                 }
            }
            break;
        }
    }


    if (flag){
        for (int i = 0; i < n; i++){
           printf("%d ", arr[i]);
        }
    }else{
        printf("-1");
    }
}
