#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char arr[100];
	
	int i =0;
	
	int k=0;
	
	
	while(scanf("%c", &arr[i])==1 && arr[i] != '\n'){
		
		i++;	
		
	}
	
	

		
	while(arr[k] == arr[(i-1)-k]){		
			
		if(k == i /2 ){
			break;
		}	
		k++;	
			
	}
	
	if(k  != (i / 2)){
		printf("0");
	}else{
		printf("1");
	}
		
	
	
	return 0;
}
