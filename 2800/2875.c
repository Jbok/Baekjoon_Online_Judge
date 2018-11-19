#include <stdio.h>

int main(){
	int female, male, k;
	scanf("%d%d%d", &female, &male, &k);
	
	int remain = 0;
	int result = 0;

	if (female > 2*male){
		remain = female - 2*male;

		if (remain >= k){
			result = male;
		}else{
			k = k - remain;
			result = male - (1 + (k-1)/3);
		}

	}else if (female < 2*male){
		int remainFemale = 0;
		int remainMale = 0;

		if ((female % 2) == 0){
			remainFemale = 0;
			remainMale = male - female/2;
		}else{
			remainFemale = 1;
			remainMale = male - female/2;
		}

		k = k - remainFemale;
		remain = remainMale;

		if (remain >= k){
			result = female/2;
		}else{
			k = k - remain;
			result = female/2 - (1 + (k-1)/3);
		}

	}else{
		if (k == 0){
			result = male;
		}else{
			result = male - (1 + (k-1)/3);
		}
	}
	
	if (result < 0){
		result = 0;
	}

	printf("%d", result);
}

