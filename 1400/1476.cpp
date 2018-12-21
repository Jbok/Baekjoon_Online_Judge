#include <iostream>

using namespace std;

int main(){

    int e, s, m;
    
    scanf("%d", &e);
    scanf("%d", &s);
    scanf("%d", &m);
    
    int i = 0;

    int flagE = e, flagM = m;
 
    if (e == 15)
        flagE = 0;
    if (m == 19)
        flagM = 0;
    
    while (1){

        int temp = i * 28 + s;

        if ( temp % 15 == flagE && temp % 19 == flagM){
            printf("%d\n", temp);
            return 0;
        }


        i++;
    }

}
