#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int floydWarshallRanks(int N, vector<pair<int, int>>& comparisons) {
    // 그래프 초기화
    vector<vector<int>> reachable(N + 1, vector<int>(N + 1, 0));

    // 비교 결과를 그래프에 반영
    for (auto& comp : comparisons) {
        int a = comp.first;
        int b = comp.second;
        reachable[a][b] = 1; // a < b
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (reachable[i][k] && reachable[k][j]) {
                    reachable[i][j] = 1;
                }
            }
        }
    }

    // 순위를 알 수 있는 학생 수 계산
    int result = 0;
    for (int i = 1; i <= N; ++i) {
        int greaterCount = 0; // i보다 큰 학생 수
        int smallerCount = 0; // i보다 작은 학생 수

        for (int j = 1; j <= N; ++j) {
            if (reachable[i][j]) greaterCount++;
            if (reachable[j][i]) smallerCount++;
        }

        if (greaterCount + smallerCount == N - 1) {
            result++;
        }
    }
    return result;
}

int main() {
    // 입력 예시
    int N = 6; // 학생 수
    vector<pair<int, int>> comparisons = {
        {1, 5},
        {3, 4},
        {5, 4},
        {4, 2},
        {4, 6},
        {5, 2}
    };

    // 함수 호출 및 결과 출력
    cout << floydWarshallRanks(N, comparisons) << endl;

    return 0;
}
