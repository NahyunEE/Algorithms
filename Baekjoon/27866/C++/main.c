#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i = 0;
    int num = 0;
    char *arr;

    arr = (char *)malloc(sizeof(char) * 1000);
    memset(arr, '0', sizeof(char) * 1000);

 
    while (scanf("%c", &arr[i]) == 1 && arr[i] != '\n') {
        i++;
        if (i == 1000)
            break;
    }

   
    scanf("%d", &num);   
    printf("%c\n", arr[num - 1]);
   

    free(arr);
    arr = NULL;

    return 0;
}

