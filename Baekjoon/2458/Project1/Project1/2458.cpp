#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int student_num=0;
	int cases=0;
	int result = 0;

	cin >> student_num >> cases;

	vector<vector<int>> vec(student_num, vector<int>(student_num,0));
	

	for (int i = 0; i < cases; ++i) {

		int row; // 키 큰 학생을 탐색
		int column; // 키 작은 학생을 탐색
		
		cin >> row >> column;

		vec[row-1][column-1] = 1;

	}

	for (int k = 0; k < student_num;++k) {

		stack<int> up_stk;
		stack<int> down_stk;
		vector<int> visited(student_num,0);

		int down_count = 0;
		int up_count = 0;


		// 작은 학생을 탐색하는 경우
		
		for (int l = 0; l < student_num;++l) {
			if (vec[k][l] == 1 && visited[l] == 0) {

				down_stk.push(l); // 작은경우가 존재하는 경우 down_stk에 저장
				down_count++;
				visited[l] = 1;

				while (!down_stk.empty()) { // down_stk이 빌 때 까지 연산 반복

					int temp = down_stk.top(); 
					down_stk.pop();

					for (int m = 0; m < student_num;++m) { 
						if (vec[temp][m] == 1 && visited[m]==0) {
							down_stk.push(m);
							visited[m] = 1;
							down_count++;
						}
					}
				}
			}
		}

		//cout << k+1 << " 보다 작은 학생의 수" << down_count << endl;

		for (int l = 0; l < student_num; ++l) {
			if (vec[l][k] == 1 && visited[l] == 0) {

				up_stk.push(l);
				visited[l] = 1;
				up_count++;

				while (!up_stk.empty()) {

					int temp = up_stk.top();
					up_stk.pop();

					for (int m = 0; m < student_num;++m) {
						if (vec[m][temp] == 1 && visited[m] == 0) {
							up_stk.push(m);
							visited[m] = 1;
							up_count++;
						}
					}

				}

			}
		}
		//cout << k+1 << " 보다 큰 학생의 수" << up_count << endl;

		int sig = up_count + down_count;
		
		if (sig == student_num - 1) {
			result++;
		}
	}

	cout << result;


	return 0;
}