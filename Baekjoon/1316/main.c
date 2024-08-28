#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int arr2[26]={0};
int temp=0;
void InitializeArr2();

int main(int argc, char *argv[]) {
	
	int num=0;
	
	char arr[100];

	
	int count=0;
	
	int i, j;
	
	
	
	scanf("%d", &num);
	
	for(i =0; i< num; ++i){ //  O(N)
		
		scanf("%s", arr);
		
		int strNum = strlen(arr); // O(N)
		
		InitializeArr2();
		
		
		for(j=0 ; j< strNum; j++){
			
			int a = arr[i] - 'a';
			
			if(arr[a] != 1){
				arr[a]=1;
			}else{
				temp=1;
				break;
			}
			
			
		}
		
		if(temp == 0){
			count++;
		}else{
			continue;
		}
		
		
	}
	
	printf("%d", count);
	
	
	
	return 0;
}

void InitializeArr2(){
		temp=0;
		memset(arr2, 0, sizeof(int) * 26);
}
