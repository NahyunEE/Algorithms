

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	unsigned int num = 0;
	unsigned int output;

	cin >> num;

	vector<unsigned int> vec(num);
	

	for (int i = 0; i < num;++i) {
		unsigned int temp = 0;
		cin >> temp;

		vec[i] = temp;
	}	

	sort(vec.begin(), vec.end());

	if (num == 1) {
		output = vec[num - 1];
	}
	else if (num == 2) {
		output = vec[num - 2];
	}else if (num % 2 == 1) { // 수열이 홀수개 일때
		output = vec[num / 2];
	}
	else { // 수열이 짝수 개일 때
		unsigned int temp1 = vec[num / 2];
		unsigned int temp2 = vec[(num / 2) - 1];

		if (temp1 < temp2) {
			output = temp1;
		}
		else {
			output = temp2;
		}		
	}

	cout << output;

}