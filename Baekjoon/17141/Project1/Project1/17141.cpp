#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define END 99999
using namespace std;

struct Point {
    int x, y;
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void CombiVirus(int M, vector<vector<Point>>& result, vector<Point>& origin, vector<Point>& arr, int start) {
    if (arr.size() == M) {
        result.push_back(arr);
        return;
    }
    for (int k = start; k < origin.size(); ++k) {
        arr.push_back(origin[k]);
        CombiVirus(M, result, origin, arr, k + 1);
        arr.pop_back(); // 백트래킹
    }
}

bool CheckZero(const vector<vector<int>>& vec, const vector<vector<int>>& visited, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (vec[i][j] == 0) {
                return true;
            }
            else if (vec[i][j] == 2 && visited[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

int SimulateSpread(int N, vector<vector<int>> vec, const vector<Point>& virus_points) {
    vector<vector<int>> visited(N, vector<int>(N, 0));
    queue<Point> q;

    for (const auto& p : virus_points) {
        q.push(p);
        visited[p.y][p.x] = 1; 
    }

    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Point t = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nx = t.x + dx[k];
                int ny = t.y + dy[k];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx] && vec[ny][nx] != 1) {
                    visited[ny][nx] = 1;
                    vec[ny][nx] = 2; 
                    q.push({ nx, ny });
                }
            }
        }
        if (!q.empty()) time++; 
    }

    return CheckZero(vec, visited,N) ? END : time;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> vec(N, vector<int>(N));
    vector<Point> virus_point;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> vec[i][j];
            if (vec[i][j] == 2) {
                virus_point.push_back({ j, i });
            }
        }
    }

    vector<vector<Point>> virus_combinations;
    vector<Point> temp;
    CombiVirus(M, virus_combinations, virus_point, temp, 0);

    int min_time = END;

    for (const auto& combination : virus_combinations) {
        int time = SimulateSpread(N, vec, combination);
        min_time = min(min_time, time);
    }

    cout << (min_time == END ? -1 : min_time) << endl;

    return 0;
}