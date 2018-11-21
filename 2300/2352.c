#include <stdio.h>

int lowBound(int arr[], int end, int value){
    
    int start = 0;
    int mid;

    while(1){
        if (start > end){
            return start;
        }
        mid = (start + end)/2;
        if (arr[mid] == value){
            return mid;
        }else if (arr[mid] < value){
            start = mid + 1;
        }else{
            end = mid -1;
        }


    }

    return mid;
}

int main(){
    int n;
    scanf("%d", &n);

    int port[40000];
    for (int i = 0; i < n; i++){
        scanf("%d", &port[i]);
    }

    int dp[40000];
    int ii = 0;
    dp[ii] = port[0];
    for (int i = 1; i <= n; i++){
        if (port[i] > dp[ii])
            dp[++ii] = port[i];
        else{
            int index = lowBound(dp, ii-1, port[i]);
            dp[index] = port[i];
        }
    }

    printf("%d", ii+1);
}
