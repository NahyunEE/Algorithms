#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    
    vector<vector<int>> vec(str1.size() + 1, vector<int>(str2.size() + 1, 0));

   
    for (int i = 1; i <= str1.size(); ++i) {
        for (int j = 1; j <= str2.size(); ++j) {
            if (str1[i - 1] == str2[j - 1]) { 
                vec[i][j] = vec[i - 1][j - 1] + 1;
            }
            else { 
                vec[i][j] = max(vec[i - 1][j], vec[i][j - 1]);
            }
        }
    }

    
    cout << vec[str1.size()][str2.size()] << endl;

    return 0;
}
