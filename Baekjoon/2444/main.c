#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int num=0;
	
	
	scanf("%d", &num);
	
	int line = 2 * num - 1;
	
	int temp_blank = line / 2;
	
	int temp_star = 1;
	
	int k,j,i;
	
	
	
	for(i=0; i <= line; ++i){

		if( i < (line / 2)){
			for(k=0; k < temp_blank ; ++k){
				printf(" ");
			}
			
			temp_blank--;
			
			for(j =0; j < temp_star; ++j){
				printf("*");
			}
			
			temp_star+=2;
			
			printf("\n");
			
		}else if(i == (line / 2)){
			for(j =0; j < line; ++j){
				printf("*");
			}
			
			temp_star = line;
			printf("\n");
			
			temp_blank++;
			temp_star-=2;
			
			
			
		}else if(i > (line / 2)){
			
			for(k=0; k < temp_blank ; ++k){
				printf(" ");
			}
			
			temp_blank++;
			
			for(j =0; j < temp_star; ++j){
				printf("*");
			}
			
			temp_star-=2;
			
			printf("\n");	
			
		}

		
	}
	
	
	
	
	
	
	
	return 0;
}
