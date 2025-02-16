#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);

// FFT 함수
void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    // 인덱스를 기준으로 짝수번째 신호와 홀수번째 신호로 나눔
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    // 분할정복으로 FFT 수행
    fft(a0, invert);
    fft(a1, invert);

    //오일러 공식 ( 시간 영역 => 주파수 영역)
    double angle = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(angle), sin(angle));

    //Cooley-Tukey 알고리즘
    for (int i = 0; i < n / 2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) { // 역변환시 주파수영역 => 시간영역
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn; // 위치조정
    }
}

// 순환 컨볼루션을 활용한 최대 내적 계산
double max_circular_score(int N, vector<int>& X, vector<int>& Y) {
    int sz = 1;
    while (sz < 2 * N) sz *= 2;  // FFT를 위한 크기 설정 (2N 이상)

    vector<cd> A(sz), B(sz);

    // X를 두 배로 확장하여 순환 컨볼루션 구현
    for (int i = 0; i < N; i++) {
        A[i] = X[i];
        A[i + N] = X[i]; // X를 2배로 확장
        B[i] = Y[N - i - 1]; // Y를 뒤집음 (순환 컨볼루션 적용)
    }

    // FFT 수행
    fft(A, false);
    fft(B, false);

    // A와 B의 곱 (컨볼루션 수행)
    for (int i = 0; i < sz; i++) {
        A[i] *= B[i];
    }

    // 역 FFT 수행
    fft(A, true);

    // 최대 내적 값 찾기
    double result = 0;
    for (int i = 0; i < N; i++) {
        result = max(result, real(A[i + N - 1]));  // 정확한 위치에서 최대값 찾기
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> Y[i];
    }

    // 순환 컨볼루션을 통한 최대 점수 출력
    cout << (long long)(max_circular_score(N, X, Y) + 0.5) << endl;  // 반올림

    return 0;
}
