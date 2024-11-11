#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int q=0;
	int k =0;
	int l=0;
	int b =0;
	int n =0;
	int f=0;
	
	scanf("%d %d %d %d %d %d",&q, &k, &l, &b, &n, &f);
	
	printf("%d %d %d %d %d %d", 1-q, 1-k, 2-l, 2-b, 2-n, 8 - f);
	
	
	
	return 0;
}
