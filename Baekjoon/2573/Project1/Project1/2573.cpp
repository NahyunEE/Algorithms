#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>


using namespace std;
int N, M;
int dy[4] = { 1, -1,0,0 };
int dx[4] = { 0,0,1,-1 };
struct Point {
	int x;
	int y;
};

int CountArea(vector<vector<int>> vec) {
	stack<Point> stk;
	int temp_count = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0;x < M; ++x) {
			if (vec[y][x] != 0) {
				temp_count++;
				stk.push({ x,y });

				while (!stk.empty()) {

					Point temp = stk.top();
					stk.pop();
					vec[temp.y][temp.x] = 0;
					
					for (int k = 0; k < 4; ++k) {
						int search_x = temp.x + dx[k];
						int search_y = temp.y + dy[k];
						if (search_x < 0 || search_x >= M || search_y <0 || search_y >= N) {
							continue;
						}
						else {
							if (vec[search_y][search_x] != 0) {
								stk.push({ search_x, search_y });
							}
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
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1, - 1,0,0 };

	cin >> N >> M; // N이 열의 갯수 , M이 행의갯수

	vector<vector<int>> vec(N, vector<int>(M, 0));
	vector<vector<int>> zero(N, vector<int>(M, 0));
	for (int y = 0; y < N; ++y) {
		for (int x = 0;x < M; ++x) {
			cin >> vec[y][x];
			zero[y][x] = 0;
		}
	}




	while (count < 2) {
		result++;
		// 한 루프당 빙하들의 인접면을 계산하고 인접면의 0 의 갯수에 따라 숫자를 차감한다.
		
		for (int y = 0; y < N; ++y) {
			for (int x = 0;x < M; ++x) { 
				if (vec[y][x] != 0) {
					
					int count_zero = 0;
					for (int k = 0; k < 4; ++k) {
						int search_x = x + dx[k];
						int search_y = y + dy[k];
						if (search_x < 0 || search_x >= M || search_y <0 || search_y >= N) {
							continue;
						}
						else {
							if (vec[search_y][search_x] == 0) zero[y][x]++;
							}
					}
				}
			}
		}

		for (int y = 0; y < N; ++y) {
			for (int x = 0;x < M; ++x) {
				vec[y][x] = vec[y][x] - zero[y][x] < 0 ? 0 : vec[y][x] - zero[y][x];
				zero[y][x] = 0;
			}
		}
		
		//전체 빙산의 갯수를 계산한다.
		count = CountArea(vec);
	}

	cout << result;


}