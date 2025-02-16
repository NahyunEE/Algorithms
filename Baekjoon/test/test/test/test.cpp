#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

#define l_long unsigned long long
#define u_short unsigned short
#define u_int unsigned int

using namespace std;

int main() {
    while (true) {
        string line;
        getline(cin, line);


        if (line.empty()) break;

        vector<u_int> case_data;
        stringstream ss(line);
        string temp;


        while (ss >> temp) {
            case_data.push_back(stoi(temp));
        }

        // ���Ͱ� ��� �ִ� ��� ó��
        if (case_data.empty()) break;

        // ���� ���� (ù ��° ���ڰ� 0�̸� ����)
        if (case_data[0] == 0) break;

        u_int n = case_data[0]; // ù��° ���ڴ� �簢���� ����
        case_data.erase(case_data.begin()); // ù��° ���ڸ� ���ּ� ��� ���Ҹ� ��ĭ�� ������


        stack<u_int> stk;
        l_long max_area = 0;

        for (u_int i = 0; i < n; ++i) {
            while (!stk.empty() && case_data[stk.top()] > case_data[i]) {
                u_int height = case_data[stk.top()];
                stk.pop();
                u_int width = stk.empty() ? i : (i - stk.top() - 1);
                max_area = max(max_area, (l_long)height * width);
            }
            stk.push(i);
        }

//9 3 1 5 6 2 4 4 2 2
        while (!stk.empty()) {
            u_int height = case_data[stk.top()];
            stk.pop();
            u_int width = stk.empty() ? n : (n - stk.top() - 1);
            max_area = max(max_area, (l_long)height * width);
        }

        cout << max_area << endl;
    }

    return 0;
}
