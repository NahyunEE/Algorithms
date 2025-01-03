#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> 
using namespace std;

struct Point {
    int x;
    int y;
};

struct Point_Pair {
    int search_x;
    int search_y;
    int near_x;
    int near_y;
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

// 최대 연속 길이를 계산하는 함수
int calculateMax(vector<vector<char>>& vec, Point A, Point B, int N) {
    // 두 점 스왑
    swap(vec[A.y][A.x], vec[B.y][B.x]);

    int max_length = 0;

    // 가로와 세로를 각각 탐색
    for (int y = 0; y < N; ++y) {
        int row_count = 1, col_count = 1;
        for (int x = 1; x < N; ++x) {
            // 가로 탐색
            if (vec[y][x] == vec[y][x - 1]) {
                row_count++;
            }
            else {
                max_length = max(max_length, row_count);
                row_count = 1;
            }

            // 세로 탐색
            if (vec[x][y] == vec[x - 1][y]) {
                col_count++;
            }
            else {
                max_length = max(max_length, col_count);
                col_count = 1;
            }
        }
        max_length = max(max_length, row_count);
        max_length = max(max_length, col_count);
    }

    // 스왑 복원
    swap(vec[A.y][A.x], vec[B.y][B.x]);

    return max_length;
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> vec(N, vector<char>(N, '\0'));
    vector<Point_Pair> stamp;

    // 입력 받기
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> vec[i][j];
        }
    }

    // 모든 가능한 포인트 쌍 검사
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Point search_point = { j, i };

            for (int k = 0; k < 4; ++k) {
                Point near_point = { search_point.x + dx[k], search_point.y + dy[k] };

                if (near_point.x < 0 || near_point.y < 0 || near_point.x >= N || near_point.y >= N) {
                    continue;
                }

                if (vec[near_point.y][near_point.x] != vec[search_point.y][search_point.x]) {
                    bool already_checked = false;

                    for (const auto& pair : stamp) {
                        if ((pair.search_x == near_point.x && pair.search_y == near_point.y &&
                            pair.near_x == search_point.x && pair.near_y == search_point.y) ||
                            (pair.search_x == search_point.x && pair.search_y == search_point.y &&
                                pair.near_x == near_point.x && pair.near_y == near_point.y)) {
                            already_checked = true;
                            break;
                        }
                    }

                    if (!already_checked) {
                        stamp.emplace_back(Point_Pair{ search_point.x, search_point.y, near_point.x, near_point.y });
                    }
                }
            }
        }
    }

    // 최대 연속 길이 계산
    int max_result = 0;
    for (const auto& pair : stamp) {
        max_result = max(max_result, calculateMax(vec, { pair.search_x, pair.search_y }, { pair.near_x, pair.near_y }, N));
    }

    cout << max_result << endl;

    return 0;
}
