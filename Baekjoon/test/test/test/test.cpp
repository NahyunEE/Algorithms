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

        // 벡터가 비어 있는 경우 처리
        if (case_data.empty()) break;

        // 종료 조건 (첫 번째 숫자가 0이면 종료)
        if (case_data[0] == 0) break;

        u_int n = case_data[0]; // 첫번째 인자는 사각형의 갯수
        case_data.erase(case_data.begin()); // 첫번째 인자를 없애서 모든 원소를 한칸씩 앞으로


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
