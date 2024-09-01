#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 5
#define MAX_COLUMNS 16 // 왜 2차원 배열의 멕스 값은 15인데 16으로 했냐면 엔터를 칠때마다 처리가 될 \n문자고 고려해서 최대길이를 만들어주어야한다. 

int main() {
    int i, x, y;
    int k, l;
    char **arr;
    int col = 0;

    
    arr = (char **)malloc(sizeof(char*) * MAX_LINES);
    for (i = 0; i < MAX_LINES; ++i) {
        arr[i] = (char *)malloc(sizeof(char) * (MAX_COLUMNS + 1));
        memset(arr[i], '\0', sizeof(char) * (MAX_COLUMNS + 1));
    }

  
    y = 0;
    while (y < MAX_LINES && fgets(arr[y], MAX_COLUMNS + 1, stdin)) {
        int len = strlen(arr[y]);
        printf("len is %d\n", len);
        
		if (len > 0 && arr[y][len - 1] == '\n') { // 마지막 16번째 자리에 \n이 들어오면 이걸 \0으로 바꿔준다. (15번째 까지는 유지한다) 
            arr[y][len - 1] = '\0';
        }
       
        if (len - 1 > col) { // (/n)까지 합하면 len이 최대 16까지 나오는데  가로길이는 이보다 -1 작은 숫자이다. 
            col = len - 1;
        }
        y++;
    }
    
    
    
   
    for (k = 0; k < col; ++k) {
        for (l = 0; l < MAX_LINES; ++l) {
            if (k < strlen(arr[l])) { 
                printf("%c", arr[l][k]);
            }
        }
    }
   

    
    for (i = 0; i < MAX_LINES; ++i) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

