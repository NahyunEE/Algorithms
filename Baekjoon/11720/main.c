#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num;
    int sum = 0;
    int i = 0;
    
    scanf("%d", &num);
    getchar(); // 숫자 입력 후 남아있는 '\n'을 제거

    for (i = 0; i < num; ++i) {
        char temp;
        scanf("%c", &temp);
        
       
        if (temp >= '0' && temp <= '9') {
            int temp2 = temp - '0'; 
            sum += temp2;
        } 
    }

    printf("%d\n", sum); 

    return 0;
}

