// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
std::vector < std::vector<int> > arr1 = {
    { 1,2,3 },
    {4,5,6},
    {7,8,9 }
};

int arr2[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};


int main()
{
    int output[3][3] = { 0 };

    int n = 3;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            output[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                output[i][j] = output[i][j] + arr1[i][k] * arr2[k][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << output[i][j]<<'\t';
        }
        cout << '\n';
    }



}
