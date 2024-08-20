#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char temp;
    int count = 0; 
    
   
    while (scanf("%c", &temp) == 1 && temp != '\n') {
        count++;
    }
    
    // Output the count of characters
    printf("%d\n", count);
    
    return 0;
}

