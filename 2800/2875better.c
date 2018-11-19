#include <stdio.h>

int main(){
	int female, male, k;
	scanf("%d%d%d", &female, &male, &k);

	while(1){
		if (k == 0){
			break;
		}

        if (female > 2*male){
            female--;
        }else{
            male--;
        }

        k--;
	}

    printf("%d", (female > 2*male) ? male : female/2);
}   

