#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string strA;
    string strB;

    cin >> strA >> strB;

    int lenA = strA.length();
    int lenB = strB.length();

    int dif = lenB - lenA;

    int resultMin = lenB;

    for (int i = 0; i <= dif; i++){
        int temp = 0;
        for (int j = 0; j < lenA; j++){
            if (strA[j] != strB[i+j])
                temp++;
        }

        if (resultMin > temp){
            resultMin = temp;
        }
    }

    cout << resultMin << endl;

}
