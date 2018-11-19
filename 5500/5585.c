#include <stdio.h>

int main(){
	int price;
	scanf("%d", &price);

	price = 1000 - price;

	int fiveHundred = 0;
	int oneHundred = 0;
	int fiveTen = 0;
	int oneTen = 0;
	int five = 0;
	int one = 0;

	while(1){
		if(price / 500 == 0)
			break;
		else{
			fiveHundred += 1;
			price = price - 500;
		}
	}

	
	while(1){
		if(price / 100 == 0)
			break;
		else{
			oneHundred += 1;
			price = price - 100;
		}
	}

	while(1){
		if(price / 50 == 0)
			break;
		else{
			fiveTen += 1;
			price = price - 50;
		}
	}
	
	while(1){
		if(price / 10 == 0)
			break;
		else{
			oneTen += 1;
			price = price - 10;
		}
	}
	
	while(1){
		if(price / 5 == 0)
			break;
		else{
			five += 1;
			price = price - 5;
		}
	}

	while(1){
		if(price / 1 == 0)
			break;
		else{
			one += 1;
			price = price - 1;
		}
	}

	printf("%d", fiveHundred + oneHundred + fiveTen + oneTen + five + one);
}
