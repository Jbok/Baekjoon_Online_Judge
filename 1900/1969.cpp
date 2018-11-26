#include <iostream>
#include <string>

using namespace std;

int main(){

    int n, m;
    cin >> n;
    cin >> m;

    string dna[1000];

    // string 입력 받기
    for (int i = 0; i < n; i++){
        cin >> dna[i];
    }

    string result;

    // 입력 받은 DNA들을 첫번째 문자부터 탐색 
    // 첫번째 DNA의 첫번째 문자
    // 두번째 DNA의 첫번째 문자
    // 세번째 DNA의 첫번째 문자
    // ...
    // n번째 DNA의첫번째 문자
    // 첫번째 DNA의 두번째 문자
    // ...
    // 순서로 탐색
    for (int i = 0; i < m; i++){

        int flag[4] = {0, 0, 0, 0}; //A, C, G, T


        for (int j = 0; j < n; j++){
            if (dna[j][i] == 'A'){
                flag[0]++;
            }else if(dna[j][i] == 'C'){
                flag[1]++;
            }else if(dna[j][i] == 'G'){
                flag[2]++;
            }else{
                flag[3]++;
            }
        }

        int index;
        int tempMax = 0;
        for (int k = 0; k < 4; k++){
            if (flag[k] > tempMax){
                tempMax = flag[k];
                index = k;
            }
        }

        if (index == 0){
            result += 'A';
        }
        else if(index == 1){
            result += 'C';
        }
        else if(index == 2){
            result += 'G';
        }
        else{
            result += 'T';   
        }
    }

    // 해밍디스턴스 값을 계산
    int hamingDistance = 0;
    for (int i=0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dna[i][j] != result[j])
                hamingDistance++;
        }
    }

    cout << result << endl;
    cout << hamingDistance << endl;
}
