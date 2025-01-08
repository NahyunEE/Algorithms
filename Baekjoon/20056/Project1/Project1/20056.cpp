#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Fireball {
    int r, c, m, s, d;
};

const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;

int mod(int x, int n) {
    return (x % n + n) % n;
}

void moveFireballs(vector<vector<vector<Fireball>>>& grid, vector<Fireball>& fireballs) {
    vector<vector<vector<Fireball>>> newGrid(N, vector<vector<Fireball>>(N));

    for (auto& fb : fireballs) {
        int nr = mod(fb.r + dx[fb.d] * fb.s, N);
        int nc = mod(fb.c + dy[fb.d] * fb.s, N);
        fb.r = nr;
        fb.c = nc;
        newGrid[nr][nc].push_back(fb);
    }

    grid = newGrid;
}

void splitFireballs(vector<vector<vector<Fireball>>>& grid, vector<Fireball>& fireballs) {
    vector<Fireball> newFireballs;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (grid[r][c].size() == 0) continue;

            if (grid[r][c].size() == 1) {
                newFireballs.push_back(grid[r][c][0]);
                continue;
            }

            int totalM = 0, totalS = 0, odd = 0, even = 0, count = grid[r][c].size();
            for (auto& fb : grid[r][c]) {
                totalM += fb.m;
                totalS += fb.s;
                if (fb.d % 2 == 0) ++even;
                else ++odd;
            }

            int newM = totalM / 5;
            if (newM == 0) continue;

            int newS = totalS / count;
            vector<int> newDirections = (even == count || odd == count) ? vector<int>{0, 2, 4, 6} : vector<int>{ 1, 3, 5, 7 };

            for (int d : newDirections) {
                newFireballs.push_back({ r, c, newM, newS, d });
            }
        }
    }

    fireballs = newFireballs;
}

int main() {
    cin >> N >> M >> K;

    vector<Fireball> fireballs;
    vector<vector<vector<Fireball>>> grid(N, vector<vector<Fireball>>(N));

    for (int i = 0; i < M; ++i) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        --r; --c;
        fireballs.push_back({ r, c, m, s, d });
    }

    for (int k = 0; k < K; ++k) {
        moveFireballs(grid, fireballs);
        splitFireballs(grid, fireballs);
    }

    int totalMass = 0;
    for (auto& fb : fireballs) {
        totalMass += fb.m;
    }

    cout << totalMass << endl;

    return 0;
}
