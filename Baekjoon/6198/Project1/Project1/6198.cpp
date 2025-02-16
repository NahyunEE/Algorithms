#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

	int N;

	cin >> N;

	
	vector<int> vec(N, 0);

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		vec[i] = temp;
	}

	stack<int> stk;
	int count = 0;
	stk.push(vec[0]);

	while (!stk.empty()) {

		count++;


		// tm
		if (vec[count] > stk.top()) {


		}




	}








}