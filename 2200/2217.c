#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return 1;
	if (num1 > num2)
		return -1;
	return 0;
}


int main(){
	int n;
	scanf("%d", &n);

	int weight[100000];

	for( int i = 0; i < n; i++){
		scanf("%d", &weight[i]);
	}

	qsort(weight, n, sizeof(int), compare);

	int result = 0;

	for (int i = 0; i < n; i++){
		int temp;
		temp = (i+1)*weight[i];

		if (result > temp){
			result = result;
		}else{
			result = temp;
		}
	}

	printf("%d", result);
}
