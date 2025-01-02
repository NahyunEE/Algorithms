#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int row = 0;
	int column = 0;
	int rec = 0;
	int count = 0;
	struct point {
		int y;
		int x;
	};

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	cin >> column >> row >> rec;

	vector<vector<int>> vec(column, vector<int>(row, 0));


	for (int i = 0; i < rec; ++i) {

		int x_1, x_2, y_1, y_2;

		cin >> x_1 >> y_1 >> x_2 >> y_2;

		for (int temp_col = y_1; temp_col < y_2 ;temp_col++) {
			for (int temp_row = x_1; temp_row < x_2 ; temp_row++) {
				vec[temp_col][temp_row] = 1;
			}
		}
	}
	
	queue<point> q;
	vector<int> vec_area;

	for (int temp_col = 0; temp_col < column; ++temp_col) {
		for (int temp_row = 0; temp_row < row; ++temp_row) {

			int area = 0;

			if (vec[temp_col][temp_row] == 0) {
				
				q.push({ temp_col, temp_row });
				vec[temp_col][temp_row] = 1;
				area++;
				count++;

				while (!q.empty()) {
					
					point temp_top = q.front();
					q.pop();


					for (int i = 0; i < 4; ++i) {
						
						point temp;

						temp.x = temp_top.x + dx[i];
						temp.y = temp_top.y + dy[i];

						if (temp.x < row && temp.y < column && temp.x >= 0 && temp.y >= 0) {
							if (vec[temp.y][temp.x] == 0) {
								q.push({ temp.y, temp.x });
								vec[temp.y][temp.x] = 1;
								area++;
							}
						}
						
					}
				}

				vec_area.push_back(area);
			}
		}
	}

	sort(vec_area.begin(), vec_area.end());

	cout << count<<'\n';

	for (int i = 0; i < vec_area.size();++i) {
		cout << vec_area[i]<<' ';
	}






}