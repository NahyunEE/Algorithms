#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int arr0[3];
	int arr1[3];
	
	char arr3[4];
	char arr4[4];
	
	int i=0;
	while(scanf("%c",&arr3[i])==1 && arr3[i]!=' '){
	
		i++;
    }
    
    arr0[0] = arr3[2] - '0';
    arr0[1] = arr3[1] - '0';
    arr0[2] = arr3[0] - '0';
    
	i=0;
	
	while(scanf("%c",&arr4[i])==1 && arr4[i]!='\n'){
	
		i++;
    }
    
    arr1[0] = arr4[2] - '0';
    arr1[1] = arr4[1] - '0';
    arr1[2] = arr4[0] - '0';
    
    
    int number1 = (arr0[0] * 100) + (arr0[1]*10) + arr0[2];
    int number2 = (arr1[0] * 100) + (arr1[1]*10) + arr1[2];
    
    if(number1 >= number2){
    	printf("%d", number1);
	}else{
		printf("%d",number2);
	}
    
    
    
    
    
	
	
	return 0;
}
