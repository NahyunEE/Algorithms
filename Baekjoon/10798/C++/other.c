#include <stdio.h>
int main(void){
    // 10798
    int i, j;
    char s[16], final[75];
    for(i=0;i<75;i++){
        final[i] = '\0';
    }
    for(i=0;i<5;i++){
        scanf("%s", s);
        for(j=0;s[j] != '\0'; j++){
            final[j*5 + i] = s[j];
        }
    }
    for(i=0;i<75;i++){
        if(final[i] == '\0'){
            continue;
        }
        printf("%c", final[i]);
    }
    return 0;
}
