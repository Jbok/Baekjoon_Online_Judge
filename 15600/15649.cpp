#include <stdio.h>

using namespace std;

void permutation(int n, int r, int index, int height, int arr[], int output[], int flag[]){

    int temparr[9] = {0, };
    for (int i = 0; i < 9; i++){
        temparr[i] = flag[i];
    }

    output[height] = arr[index];
    temparr[index]++;


    int temp = 0;
    for (int i = 1; i <= n; i++){
        if (flag[i] > 1){
            return;
        }
        else if (flag[i] == 1){
            temp++;
        }
    }

    if (temp == r){
        for (int i = 1; i <= r; i++){
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
    }

    if (height > n)
        return;

    permutation(n, r, 1, height+1, arr, output, temparr);
    
    if (index != n){
        permutation(n, r, index+1, height, arr, output, flag);
    }
}

int main(){

    int n, r;
    scanf("%d", &n);
    scanf("%d", &r);

    int arr[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int output[9] = {0, };
    int flag[9] = {0, };

    permutation(n, r, 1, 1, arr, output, flag);


}
