#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

struct Point {
    int x;
    int y;
};

int CountArea(vector<vector<int>>& vec, vector<vector<bool>>& visited) {
    queue<Point> q;
    int temp_count = 0;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (vec[y][x] != 0 && !visited[y][x]) {
                temp_count++;
                q.push({ x, y });
                visited[y][x] = true;

                while (!q.empty()) {
                    Point temp = q.front();
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        int search_x = temp.x + dx[k];
                        int search_y = temp.y + dy[k];
                        if (search_x >= 0 && search_x < M && search_y >= 0 && search_y < N && vec[search_y][search_x] != 0 && !visited[search_y][search_x]) {
                            q.push({ search_x, search_y });
                            visited[search_y][search_x] = true;
                        }
                    }
                }
            }
        }
    }

    return temp_count;
}

int main() {
    int count = 1;
    int result = 0;

    cin >> N >> M; // N이 열의 갯수, M이 행의 갯수

    vector<vector<int>> vec(N, vector<int>(M, 0));
    vector<Point> icebergs;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> vec[y][x];
            if (vec[y][x] != 0) {
                icebergs.push_back({ x, y });
            }
        }
    }

    while (count < 2) {
        result++;
        vector<vector<int>> zero(N, vector<int>(M, 0));
        vector<Point> new_icebergs;

        // 한 루프당 빙하들의 인접면을 계산하고 인접면의 0의 갯수에 따라 숫자를 차감한다.
        for (const auto& iceberg : icebergs) {
            int x = iceberg.x;
            int y = iceberg.y;
            if (vec[y][x] != 0) {
                for (int k = 0; k < 4; ++k) {
                    int search_x = x + dx[k];
                    int search_y = y + dy[k];
                    if (search_x >= 0 && search_x < M && search_y >= 0 && search_y < N && vec[search_y][search_x] == 0) {
                        zero[y][x]++;
                    }
                }
            }
        }

        for (const auto& iceberg : icebergs) {
            int x = iceberg.x;
            int y = iceberg.y;
            vec[y][x] = max(0, vec[y][x] - zero[y][x]);
            if (vec[y][x] != 0) {
                new_icebergs.push_back({ x, y });
            }
        }

        icebergs = new_icebergs;

        // 전체 빙산의 갯수를 계산한다.
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        count = CountArea(vec, visited);

        if (icebergs.empty()) {
            result = 0;
            break;
        }
    }

    cout << result;
}