#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int arr2[26];
    memset(arr2, -1, sizeof(arr2)); // �迭 ��ü�� -1�� �ʱ�ȭ
    char temp;
    int index = 0;
	int i;
    // ���� �Է��� ����
    while (scanf("%c", &temp) == 1 && temp != '\n') {
        if (temp >= 'a' && temp <= 'z') {
            int pos = temp - 'a'; // ���ĺ� �ε��� ���
            if (arr2[pos] == -1) { // ù ���� �ø� ���
                arr2[pos] = index;
            }
        }
        index++;
    }

    // ��� ���
    for (i = 0; i < 26; ++i) {
        printf("%d ", arr2[i]);
    }

    return 0;
}

