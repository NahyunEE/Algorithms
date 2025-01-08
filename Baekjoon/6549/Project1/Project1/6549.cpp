#include <iostream>
#include <vector>
#include <sstream> // ���ڿ� ��Ʈ�� ���
using namespace std;

int main() {
    vector<vector<int>> testCases; // ��� �׽�Ʈ ���̽��� �����ϴ� ����
    string line;

    while (getline(cin, line)) { // �� �پ� �Է¹ޱ�
        if (line == "0") break; // �Է��� "0"�̸� ��ü ����

        stringstream ss(line); // ���ڿ� ��Ʈ������ ó��
        vector<int> testCase;
        int num;

        while (ss >> num) { // ��Ʈ������ ���� �б�
            testCase.push_back(num); // �׽�Ʈ ���̽��� �߰�
        }

        testCases.push_back(testCase); // �� �׽�Ʈ ���̽� ����
    }

    // ����� �׽�Ʈ ���̽� ��� (Ȯ�ο�)
    for (const auto& testCase : testCases) {
        
        int tum = 0;
        int MAX_DOWN = 0;
        int MAX_UP = 0;
        
        for (int i = 0; i < testCase.size();++i) { // 10,0000
            if (i > 0) {
                if (testCase[i] - testCase[i - 1] > tum) {
                    tum = testCase[i] - testCase[i - 1];
                    MAX_DOWN = i-1;
                    MAX_UP = i;
                }
            }
        }
        
    }

    return 0;
}
