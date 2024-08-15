#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char * arr;
    int i=0;
    int count=0;
    arr = (char*)malloc(sizeof(char)*100);
    memset(arr,'0',sizeof(char)*100);

    //Segmentation Fault: 잘못된 메모리 참조, 건드려서 안될 곳을 건드렸기 때문에 발생
    while(scanf("%c",arr[i])==1 && arr[i] != '\n'){
        count++;
        i++;
        if(i == 100)break;
    }
    printf("%d", count);

    free(arr);
    arr =NULL;

}