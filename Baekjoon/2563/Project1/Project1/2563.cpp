#include <iostream>
#include <vector>

using namespace std;

struct Paper {
	int start;
	int end;
};


int main() {

	int paper;
	int count = 0;
	cin >> paper;

	vector<vector<int>> background(100, vector<int>(100,0));

	for (int i = 0; i < paper; i++) {

		int x = 0;
		int y = 0;

		cin >> x >> y;

		x = x - 1;
		y = y - 1;

		for (int j = y; j < y + 10 && j < 100; j++) {
			for (int k = x; k < x + 10 && k < 100; k++) {
				if (background[j][k] == 1) {
					count++;
					//cout << "°ãÄ¡´Â °ø°£" << j << k << endl;
				}
				else {
					background[j][k] = 1;
				}
			}
		}



	}
	int result = (paper * 100) - count;


	cout << result;

}