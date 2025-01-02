#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<int>& board, int row, int col) {
   
    for (int i = 0; i < row; ++i) {
        int prevCol = board[i];
        
        if (prevCol == col) return false;
       
        if (abs(prevCol - col) == abs(i - row)) return false;
    }
    return true;
}

void solveNQueens(int N) {
    vector<int> board(N, -1);  
    int solutionCount = 0;  
    int row = 0;  

    while (row >= 0) {
        bool placed = false; 
        for (int col = (board[row] == -1 ? 0 : board[row] + 1); col < N; ++col) {
            if (isSafe(board, row, col)) {
                board[row] = col;
                placed = true;
                break;
            }
        }

        if (placed) {
           
            if (row == N - 1) {
            
                solutionCount++;
                board[row] = -1; 
                --row;
            }
            else {
               
                ++row;
            }
        }
        else {
            
            board[row] = -1;  
            --row;
        }
    }

    cout << solutionCount << endl;
}

int main() {
    int N;
    
    cin >> N;

    solveNQueens(N);

    return 0;
}
