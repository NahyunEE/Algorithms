#include <iostream>
#include <vector>
#include <queue>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

struct Point {
    int x, y;
};

struct Node {
    Point p;
    int direct;
};

int N, M;



bool isWithinBounds(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

void pushNode(queue<Node>& q, int x, int y, int direction) {
    q.push({ {x, y}, direction });
  
}

int main() {
    cin >> N >> M;

    Node start;
    cin >> start.p.y >> start.p.x >> start.direct;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];

    queue<Node> q;
    q.push(start);

    int dx[] = { 0, 1, 0, -1 }; // NORTH, EAST, SOUTH, WEST
    int dy[] = { -1, 0, 1, 0 };

    int count = 0;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (grid[current.p.y][current.p.x] == 0) {
            ++count;
            grid[current.p.y][current.p.x] = 2; 
        }

        bool foundEmpty = false;
        for (int i = 0; i < 4; ++i) {
            int nx = current.p.x + dx[i];
            int ny = current.p.y + dy[i];
            if (isWithinBounds(nx, ny) && grid[ny][nx] == 0) {
                foundEmpty = true;
                break;
            }
        }

        if (foundEmpty) {
            int leftDirection = (current.direct + 3) % 4;
            int nx = current.p.x + dx[leftDirection];
            int ny = current.p.y + dy[leftDirection];

            if (isWithinBounds(nx, ny) && grid[ny][nx] == 0) {
                pushNode(q, nx, ny, leftDirection);
            }
            else {
                pushNode(q, current.p.x, current.p.y, leftDirection);
            }
        }
        else {
            int backDirection = (current.direct + 2) % 4;
            int nx = current.p.x + dx[backDirection];
            int ny = current.p.y + dy[backDirection];

            if (isWithinBounds(nx, ny) && grid[ny][nx] != 1) {
                pushNode(q, nx, ny, current.direct);
            }
            else {
                break; 
            }
        }
    }

    cout << count << endl;
    return 0;
}
