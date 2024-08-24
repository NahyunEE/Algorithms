#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char arr[16];
	
	int i=0;
	
	int count=0;
	
	
	while(scanf("%c",&arr[i])==1 && arr[i] != '\n'){
		
	
	if(arr[i] >64 && arr[i]<68 ){ // 65. 66, 67 A B C
		count+=3;
	}else if( arr[i]>67 && arr[i]<71){ // DEF
		count+=4;
	}else if( arr[i]>70 && arr[i]<74){//GHI
		count+=5;
	}else if( arr[i]>73 && arr[i]<77){//JKL
		count+=6;
	}else if( arr[i]>76 && arr[i]<80){//MNO
		count+=7;
	}else if( arr[i]>79 && arr[i]<84){//PQRS
		count+=8;
	}else if( arr[i]>83 && arr[i]<87){//TUV
		count+=9;
	}else if( arr[i]>86 && arr[i]<91){//WXYZ
		count+=10;
	}
	
	i++;
	}
	
	printf("%d", count);
	
	
	
	
	
	
	return 0;
}
