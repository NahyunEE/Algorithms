#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i=0;
	int j=0;
	int result_x=0;
	int result_y=0;
	int max=0;
	
	for(i=0; i< 9;++i){
		for(j=0; j < 9; ++j){
			
			int temp;
			scanf("%d",&temp);
			
			if(max < temp){
				max = temp;
				result_x = j;
				result_y = i;
			}
						
			
		}
	}
	
	printf("%d \n%d %d", max, (result_y+1), (result_x+1));
	
	
	
	
	return 0;
}
