#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int num=0;
	int i=0;
	int k=0;
	int l=0;
	
	scanf("%d", &num);
	getchar(); // 버퍼에 남아있는 개행문자를 제거한다. 
	
	char * arr2;
	arr2 = malloc(sizeof(char)*1000);
	
	
	for(i=0; i< num;++i){
		char * arr;
		
		arr  = malloc(sizeof(char)*1000);
		
		while(scanf("%c", &arr[k])==1 && arr[k] != '\n'){
			k++;
		}
		
		arr2[l] = arr[0];
		l++;
		arr2[l] = arr[k-1];
		l++;
		
		k=0;
		
		
		free(arr);

		arr = NULL;			
		
		
	}
	
	for(i=0; i< l;++i){
		
		printf("%c",arr2[i]);
		if(i%2==1)printf("\n");
		
	} 
	
	
	free(arr2);
	arr2 =  NULL;
	
	
	
	return 0;
}
