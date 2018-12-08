#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

    int *prime = new int[1000001];

    for (int i = 1; i < 1000001; i++){
        for (int j = 1; j <= 1000001/i; j++){
            prime[i*j] = prime[i*j] + 1;
        }
    }

    int n;
    while(1){
        cin >> n;

        if (n == 0){
            return 0;
        }

        bool flag = false;

        for (int i = n; i >= n/2; i--){
            if ( prime[i] == 2 && prime[n-i] == 2){
                printf("%d = %d + %d\n", n, n-i, i);
                flag = true;
                break;
            }
        }

        if (!flag){
            printf("Goldbach's conjecture is wrong.\n");   
        }
    }

}
