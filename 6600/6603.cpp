#include <iostream>

using namespace std;

void Combination(int n, int depth, int start, int arr[], int result[])
{
    if (depth == 6){
        for (int i = 0; i < 6; i++){
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }   

    for (int i = start; i < n; i++){
        result[depth] = arr[i];

        if (n - i + depth >= 6)
            Combination(n , depth + 1, i+1, arr, result);
        else
            return;
    }

}

int main(){
     
    int n;

    cin >> n;

    while (n != 0){
        int* result = new int[n];
        int* arr = new int[n];

        for (int i = 0; i < n; i++){
            cin >> arr[i];        
        }

        Combination(n, 0, 0, arr, result);
        printf("\n");
        delete[] arr;
        delete[] result;

        cin >> n;
    }

}
