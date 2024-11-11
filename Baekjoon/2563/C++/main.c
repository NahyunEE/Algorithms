#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	int arr[100][100];
	memset(arr, 0, sizeof(int)*10000);
	int i=0; 
	int num=0;
	int temp_x, temp_y;
	scanf("%d", &num);
	
	for(i=0; i< num; ++i){ //최대 100 
		
		int x=0;
		int y=0;
		
		scanf("%d %d", &x, &y);
		
		for(temp_y= (y-1); temp_y< (y+9) ; ++temp_y){ // 최대 10 
			for(temp_x = (x-1); temp_x < (x+9);++temp_x){ // 최대 10 
				arr[temp_y][temp_x]=1;
			}
		}		
		
	}
	
	int x,y;
	int count=0;
	for(y=0; y<100;++y){
		for(x=0; x < 100; ++x){
			if(arr[y][x]==1){
				count++;
			}
		}
	}
	
	printf("%d",count);
	
	
	
	
	
	return 0;
}
