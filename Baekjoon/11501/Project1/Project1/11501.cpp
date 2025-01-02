#define t_long long long
#define t_short unsigned short
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {

	int testcase;
	int day;
	t_long sum = 0;

	cin >> testcase;

	vector<t_long> result(testcase);


	struct stock {
		int index;
		t_short value;
	};


	for (int i = 0; i < testcase;++i) {
		
		cin >> day;

		vector<stock> vec(day);
		vector<short> visited(day);
		queue<stock> q;
		sum = 0;


		for (int k = 0; k < day; ++k) {
			t_short temp;
			cin >> temp;			
			vec[k].index = k;
			vec[k].value = temp;
			visited[k] = 0;
		}

		sort(vec.begin(), vec.end(), [](const stock& a, const stock& b) {
			return a.value > b.value;  
		});

		for (int k = 0; k < day; ++k) {
			//cout << vec[k].value << endl;
			q.push(vec[k]);
		}

		while (!q.empty()) {

			stock temp = q.front();
			t_long temp_sum=0;
			
			int t = temp.index;

			while (t >= 0 && visited[t] != 1) {
				temp_sum += (temp.value - vec[t].value);
				visited[t] = 1;
				t--;
			}

			sum += temp_sum;
			q.pop();
		}

		result[i] = sum;
	}

	for (int i = 0; i < testcase; ++i) {
		cout << result[i] << endl;
	}





	



}