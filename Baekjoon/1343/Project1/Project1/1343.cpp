#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str;
    cin >> str;

    vector<char> output(str.size(), '.');  

    int i = 0;
    int count = 0;
    int temp = 0;
    int j = 0;
    int k = 0;
    bool sig = true;

    while (i < str.size()) {  
        if (str[i] == '.' && count == 0) {
            output[i] = str[i];  
        }
        else if (str[i] == 'X') {  
            count++;
            if (i == str.size() - 1) {  
                if (count >= 4) {
                    if (count % 4 == 0) {
                        for (j = (i - count +1 ); j <= i; ++j) {
                            output[j] = 'A';
                        }
                    }
                    else if (count % 2 == 0 && count % 4 != 0) {
                        for (k = (i - count+1); k <= (i - 2); k++) {
                            output[k] = 'A';
                        }
                        output[i - 1] = 'B';
                        output[i] = 'B';
                    }
                    else {
                        sig = false;
                        break;
                    }
                }
                else if (count == 3) {
                    sig = false;
                    break;
                }
                else if (count == 2) {
                    output[i] = 'B';
                    output[i - 1] = 'B';
                }
                else if (count == 1) {
                    sig = false;
                    break;
                }
                count = 0;
            }
        }
        else if (str[i] == '.' && count != 0) {  
            if (count >= 4) {
                if (count % 4 == 0) {
                    for (j = (i - count); j < i; ++j) {
                        output[j] = 'A';
                    }
                }
                else if (count % 2 == 0 && count % 4 != 0) {
                    for (k = (i - count); k < (i - 2); k++) {
                        output[k] = 'A';
                    }
                    output[i - 2] = 'B';
                    output[i - 1] = 'B';
                }
                else {
                    sig = false;
                    break;
                }
            }
            else if (count == 3) {
                sig = false;
                break;
            }
            else if (count == 2) {
                output[i - 1] = 'B';
                output[i - 2] = 'B';
            }
            else if (count == 1) {
                sig = false;
                break;
            }
            count = 0;
        }
        i++;
    }

    if (sig) {
       
        for (int l = 0; l < str.size(); l++) {
            cout << output[l];
        }
    }
    else {
        cout << "-1" << endl;  
    }

    return 0;
}
