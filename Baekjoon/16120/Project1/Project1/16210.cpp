#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

    string str;
    cin >> str;

    stack<char> stk;

    for (int i = 0; i < str.size(); ++i) {
        
        stk.push(str[i]); 

        
        if (stk.size() >= 4) {
            char stk_4 = stk.top(); stk.pop();
            char stk_3 = stk.top(); stk.pop();
            char stk_2= stk.top(); stk.pop();
            char stk_1 = stk.top(); stk.pop();

            if (stk_1 == 'P' && stk_2 == 'P' && stk_3 == 'A' && stk_4 == 'P') {
                stk.push('P'); 
            }
            else {
                
                stk.push(stk_1);
                stk.push(stk_2);
                stk.push(stk_3);
                stk.push(stk_4);
            }
        }
    }



    if (stk.size() == 1 && stk.top() == 'P') {
        cout << "PPAP" << endl;
    }
    else {
        cout << "NP" << endl;
    }

    return 0;
}
