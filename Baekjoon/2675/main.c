#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct Point {
    int num;
    char word[21];
};

int main(int argc, char *argv[]) {
    int testcase;
    int i=0;
	int j=0; 
	int k=0;
    scanf("%d", &testcase);
    
    struct Point p[1000];
    
    for(i = 0; i < testcase; i++) {
        scanf("%d %s", &p[i].num, p[i].word);
    }
    
    for(i = 0; i < testcase; i++) {
        int wordsize = strlen(p[i].word); 
        
        for(j = 0; j < wordsize; j++) {
            for(k = 0; k < p[i].num; k++) {
                printf("%c", p[i].word[j]);
            }
        }
        printf("\n"); 
    }
    
    return 0;
}

