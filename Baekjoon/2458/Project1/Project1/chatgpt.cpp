#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int floydWarshallRanks(int N, vector<pair<int, int>>& comparisons) {
    // �׷��� �ʱ�ȭ
    vector<vector<int>> reachable(N + 1, vector<int>(N + 1, 0));

    // �� ����� �׷����� �ݿ�
    for (auto& comp : comparisons) {
        int a = comp.first;
        int b = comp.second;
        reachable[a][b] = 1; // a < b
    }

    // �÷��̵�-���� �˰���
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (reachable[i][k] && reachable[k][j]) {
                    reachable[i][j] = 1;
                }
            }
        }
    }

    // ������ �� �� �ִ� �л� �� ���
    int result = 0;
    for (int i = 1; i <= N; ++i) {
        int greaterCount = 0; // i���� ū �л� ��
        int smallerCount = 0; // i���� ���� �л� ��

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
    // �Է� ����
    int N = 6; // �л� ��
    vector<pair<int, int>> comparisons = {
        {1, 5},
        {3, 4},
        {5, 4},
        {4, 2},
        {4, 6},
        {5, 2}
    };

    // �Լ� ȣ�� �� ��� ���
    cout << floydWarshallRanks(N, comparisons) << endl;

    return 0;
}
