#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
	int x;
	int y;
};

struct Node {
	Point p;
	int direct;
};



int N = 0;
int M = 0;
bool calc=true;

int main() {

	
	int count = 0;
	Node start;

	cin >> N >> M;
	cin >> start.p.y >> start.p.x >> start.direct;

	vector<vector<int>> vec(N, vector<int>(M, 0));
	queue<Node> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> vec[i][j];
		}
	}

	q.push(start);

	

}
