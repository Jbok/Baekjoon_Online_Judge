#include <iostream>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    int large = n > m ? n : m;
    int small = n < m ? n : m;

    int gcd;

    for (int i = small; i > 0; i--){
        if ( n%i == 0 && m%i == 0 ){
            gcd = i;
            break;
        }
    }
    
    int lcm = large;
    while(1){
        if( lcm%n == 0 & lcm%m == 0)
            break;
        else
            lcm++;
    }

    cout << gcd << endl;
    cout << lcm << endl;

}
