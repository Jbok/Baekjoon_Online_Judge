#include <iostream>

using namespace std;

void permutation(int n, int depth, int arr[], int flag[]){

    if (n == depth){
        for (int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++){
        if (flag[i] == 0){
            arr[depth] = i+1;
            flag[i] = 1;
            permutation(n , depth+1, arr, flag);
            flag[i] = 0;
        }
    }

}

int main(){

    int n;

    scanf("%d", &n);

    int *arr = new int[n];

    int flag[8] = {0, }; 

    permutation(n, 0, arr, flag);
}
