#include <stdio.h>

int main(){
  
	int n;
	int p[1000];
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}

	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (p[i] > p[j]){
				int temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}	

	int resultN = 0;
	int resultTotal = 0;

	for (int i = 0; i < n; i++){
		resultN = resultN + p[i];
		resultTotal += resultN;
	}

	printf("%d", resultTotal);

}

