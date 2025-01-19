#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool isBlack(int s, int r, int c, int N, int K) {
    while (s > 0) {
        int size = pow(N, s - 1); 
        int center_start = (N - K) / 2 * size; 
        int center_end = center_start + K * size; 

        if (center_start <= r && r < center_end && center_start <= c && c < center_end) {
            return true; 
        }
              
        r %= size;
        c %= size;
        s--;
    }
    return false; 
}


int main() {
   
    int s, N, K, R1, R2, C1, C2;
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

   
    vector<string> result;
    for (int r = R1; r <= R2; r++) {
        string row = "";
        for (int c = C1; c <= C2; c++) {
            if (isBlack(s, r, c, N, K)) {
                row += '1'; 
            }
            else {
                row += '0'; 
            }
        }
        result.push_back(row);
    }

  
    for (const string& row : result) {
        cout << row << '\n';
    }

    return 0;
}
