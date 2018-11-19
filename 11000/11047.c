#include <stdio.h>

int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    int cost[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &cost[i]);
    }

    int number = 0;
    for (int j = n-1; j >= 0; j--){
        int temp = k / cost[j];
        k -= temp * cost[j];

        number += temp;
    }

    printf("%d", number);
}
