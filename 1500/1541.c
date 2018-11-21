#include <stdio.h>
#include <string.h>
#include <math.h>

int stringToNum(char str[], int end){
    int result = 0;
    double j = 0;
    
    for (int i = end; i >= 0; i--){
        result += (str[i] - '0') * (int)(pow(10.0, j++) + 0.5);
    }

    return result;
}

int main(){
    char str[50];
    scanf("%s", str);

    int temp[50];
    int k = 0;
    int oper[50];
    int l = 0;

    char buf[5];
    int j = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] != '-' && str[i] != '+'){
            buf[j++] = str[i];
        }else{
            oper[l++] = str[i];
            temp[k++] = stringToNum(buf, j-1);
            j = 0;
        }
    }
    
    temp[k++] = stringToNum(buf, j-1);
 
    int index = l;
    for (int i = 0; i < l; i++){
        if (oper[i] == '-'){
            index = i;
            break;
        }
    }

    int result = 0;
    for (int i = 0; i < k; i++){
        if (i <= index)
            result += temp[i];
        else
            result -= temp[i];

    }
    
    printf("%d", result);

}
