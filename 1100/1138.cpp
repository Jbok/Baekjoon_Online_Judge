#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int next[10];
    int result[10];
    for (int i = 0; i < n; i++){
        cin >> next[i];
        result[i] = -1;
    }

    for (int i = 0; i < n; i++){
        int k = 0;
        while(1){
            if (result[k] == -1 && next[i] != 0){
                next[i]--;
                k++;
            }else if (result[k] != -1){
                k++;
            }else{
                result[k] = i+1;
                break;
            }
        }
    }


    for (int i = 0; i < n; i++){
        cout << result[i] << ' ';
    }
}
