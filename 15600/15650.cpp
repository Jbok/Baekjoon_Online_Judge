#include <stdio.h>

void doCombination(int n, int r, int index, int height, int output[]){

    if (height > r){
        for (int i = 1; i <= r; i++){
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
    }

    if (index > n)
        return;

    output[height] = index;

    doCombination(n, r, index+1, height+1, output);
    doCombination(n, r, index+1, height, output);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    int output[9] = {0, };
    doCombination(n, m, 1, 1, output);

}
