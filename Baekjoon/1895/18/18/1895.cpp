#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// N은 가로, m은 세로

	int row, col;
	int temp_x = 0;
	int temp_y = 0;
	int result = 0;
	int T = 0;

	cin >> col>> row;

	vector<vector<int>> vec(col, vector<int>(row, 0));

	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			int temp;
			cin >> temp;

			vec[i][j] = temp;

		}
	}

	cin >> T;

	for (temp_y=0;  temp_y < col-2; ++temp_y) {
		for (temp_x=0; temp_x < row - 2; ++temp_x) {
			    
			vector<int> filtered_vec(9, 0);
			int m = 0;

			for (int i = temp_y; i <= temp_y + 2; i++) {
				for (int j = temp_x; j <= temp_x + 2; j++) {
					filtered_vec[m] = vec[i][j];
					m++;
				}
			}

			sort(filtered_vec.begin(), filtered_vec.end());

			if (filtered_vec[4] >= T) {
				result++;
			}


			m = 0;			
		}
	}

	cout << result;








	



	


}