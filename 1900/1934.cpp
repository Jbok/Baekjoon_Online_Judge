#include <iostream>

using namespace std;

int GCD(int a, int b){

    int large = a > b ? a : b;
    int small = a < b ? a : b;
    int flag = 1;

    while (1){
        
        if((large*flag)%small == 0)
            break;
        else
            flag++;
    }

    return large*flag;
}

int main(){

    int t;
    cin >> t;

    int a[1000];
    int b[1000];

    for (int i = 0; i < t; i++){
        cin >> a[i] >> b[i];
    }
    
    for (int i = 0; i < t; i++){
        cout << GCD(a[i], b[i]) << endl;
    }
}
