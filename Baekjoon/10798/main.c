#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 5
#define MAX_COLUMNS 16 // �� 2���� �迭�� �߽� ���� 15�ε� 16���� �߳ĸ� ���͸� ĥ������ ó���� �� \n���ڰ� ����ؼ� �ִ���̸� ������־���Ѵ�. 

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
        
		if (len > 0 && arr[y][len - 1] == '\n') { // ������ 16��° �ڸ��� \n�� ������ �̰� \0���� �ٲ��ش�. (15��° ������ �����Ѵ�) 
            arr[y][len - 1] = '\0';
        }
       
        if (len - 1 > col) { // (/n)���� ���ϸ� len�� �ִ� 16���� �����µ�  ���α��̴� �̺��� -1 ���� �����̴�. 
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

