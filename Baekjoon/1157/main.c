#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	char arr[1000001]; // 1Mbyte
	unsigned int arr2[26]={0}; // 4 byte 
	unsigned int max=0; // 4 byte
	unsigned int count=0; // 4 byte
	unsigned int i=0; //4 byte
	unsigned int result=0; // 4 byte
	

	scanf("%s",arr);
	
	int num = strlen(arr); // O(N)
	
	for(i=0; i< num; ++i){ //O(N)
		
		int temp;
		
		if(arr[i] < 'a'){
			temp = arr[i] - 'A';
			//printf("%d" , temp);
		}else{
			temp = arr[i] - 'a';
			//printf("%d", temp);
		}

		arr2[temp]++;
		
		if(arr2[temp] > max){
			max = arr2[temp];
		}
				
	}
	
	
	
	for(i=0; i <26 ; ++i){ 
		
		if(arr2[i] == max){
			count++;
			result = i;			
		}		
	
	}	
	
	if(count > 1){
		printf("?");
	}else{
		printf("%c",(char)(result + 'A'));
	}
	
	
	
	
	
	
	return 0;
}
