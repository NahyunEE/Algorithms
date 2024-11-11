#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */




int main(int argc, char *argv[]) {
	
	int num=0;
	
	char arr[100];	
	int count=0;
	int arr2[26]={-1,};
	int temp=0;
	int i, j;
	
	int a;
	
	scanf("%d", &num);
	
	for(i =0; i< num; ++i){ //  O(N) O(100)
		
		scanf("%s", arr);
		
		int strNum = strlen(arr); // O(n) O(100)
		
		temp=0;
		memset(arr2, -1, sizeof(int)*26);
		
		
		for(j=0 ; j< strNum; j++){ // O(n) O(100)
			
			a = arr[j] - 'a';
			
			//printf("%d",a);
			
			if(arr2[a] == -1 || arr2[a]== j-1){ //기존에 중복되거나 0일때 
				arr2[a]=j;
			}else{//연속되지않을때 
				temp=1;
				break;
			}
			
		}
	
		if(temp == 0){
			count++;
					
		}
		

		
	}
	
	//O(N^3) Algorithms
	 
	
	printf("%d", count);
	
	
	
	return 0;
}


