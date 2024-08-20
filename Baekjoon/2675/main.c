#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */




struct TestCase{
	int number;
	char word[20];
	
};

int main(int argc, char *argv[]) {
	
	int Test;
	struct TestCase * arr;
	int i=0;
	int j=0;
	int n=0;
	int k=0;
	
	arr=(struct TestCase*)malloc(sizeof(struct TestCase)*Test);	
	
	scanf("%d",Test);
	getchar();
	
	
	
	for(i=0; i< Test; i++){		
		scanf("%d %s", &arr[i].number, arr[i].word);	
			
	}
	
	for(j=0; j<Test; j++){ // 각각의 테스트케이스를 읽기 
		struct TestCase temp_tt=arr[j];
	
		for(k=0; k < strlen(temp_tt.word) ;++k){ //
			for(n=0,l=0; n<temp_tt.number;++n,++l){
				printf("%c",temp_tt.word[l];
			}
		}	
		
	}
	
	free(arr);
	
	
	
	return 0;
}
