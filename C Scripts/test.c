#include <stdio.h>

int main(){


	int num1 = 230 , num2 = 11 , sum = 0, t1 = 0, t2 = 1, nextTerm;
	
	for(int i=0;i<100000;i++){
	
		//calculate sum
		sum = sum + num1 * i + num2 * i * 2; 

	}

	
	printf("Result is %d", sum);
	
	return 0;
}
