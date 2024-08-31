#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int N=0;
	int M=0;
	int i=0;
	int j=0;
	int l=0;
	int k=0;
	
	int ** arr;
	int ** arr2;
	
	scanf("%d %d",&N,&M);
	//arr1
	arr = (int **)malloc(sizeof(int*)*N);
	
	memset(arr, 0, sizeof(int*)*N);
	
	for(i=0; i < N; ++i){
		arr[i] = (int *)malloc(sizeof(int)*M);
		memset(arr[i],0,sizeof(int)*M);
	}
	
	//arr2
	arr2 = (int **)malloc(sizeof(int*)*N);
	memset(arr2, 0, sizeof(int*)*N);
	
	for(i=0; i < N; ++i){
		arr2[i] = (int *)malloc(sizeof(int)*M);
		memset(arr2[i],0,sizeof(int)*M);
	}
	
	//Get value from input arr
	for(k=0; k<N;++k){
		for(l=0; l<M;++l){
			scanf("%d",&arr[k][l]);
		}
	}
	//Get value from input arr2
		for(k=0; k<N;++k){
		for(l=0; l<M;++l){
			scanf("%d",&arr2[k][l]);
		}
	}
	
	for(k=0; k < N; ++k){
		for(l=0; l<M;++l){
			arr[k][l]+=arr2[k][l];
		}
	}
		//Get value from input arr2
	for(k=0; k<N;++k){
		for(l=0; l<M;++l){
			printf("%d ",arr[k][l]);
		}
			printf("\n");
	}
	
	
	
	for(i=0; i<N;++i){
		free(arr[i]);
	}
	
	free(arr);
	
		for(i=0; i<N;++i){
		free(arr2[i]);
	}
	
	free(arr2);
	
	
	
	
	return 0;
}
