#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int port[40000];
    int dp[40000];
    for (int i = 0; i < n; i++){
        scanf("%d", &port[i]);
    }

    for (int i = 0; i < n; i++){
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if ((port[i] > port[j]) && (dp[i] < dp[j]+1)){
                dp[i] = dp[j]+1;
            }
        }
    }
    
    int resultMax = 0;
    for (int i = 0; i < n; i++){
        if (resultMax < dp[i]){
            resultMax = dp[i];
        }
    }

    printf("%d", resultMax);
}
