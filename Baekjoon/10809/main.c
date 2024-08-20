#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int arr2[26];
    memset(arr2, -1, sizeof(arr2)); // 배열 전체를 -1로 초기화
    char temp;
    int index = 0;
	int i;
    // 문자 입력을 받음
    while (scanf("%c", &temp) == 1 && temp != '\n') {
        if (temp >= 'a' && temp <= 'z') {
            int pos = temp - 'a'; // 알파벳 인덱스 계산
            if (arr2[pos] == -1) { // 첫 등장 시만 기록
                arr2[pos] = index;
            }
        }
        index++;
    }

    // 결과 출력
    for (i = 0; i < 26; ++i) {
        printf("%d ", arr2[i]);
    }

    return 0;
}

