#include <iostream>
#include <vector>
#include <sstream> // 문자열 스트림 사용
using namespace std;

int main() {
    vector<vector<int>> testCases; // 모든 테스트 케이스를 저장하는 벡터
    string line;

    while (getline(cin, line)) { // 한 줄씩 입력받기
        if (line == "0") break; // 입력이 "0"이면 전체 종료

        stringstream ss(line); // 문자열 스트림으로 처리
        vector<int> testCase;
        int num;

        while (ss >> num) { // 스트림에서 숫자 읽기
            testCase.push_back(num); // 테스트 케이스에 추가
        }

        testCases.push_back(testCase); // 한 테스트 케이스 저장
    }

    // 저장된 테스트 케이스 출력 (확인용)
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
