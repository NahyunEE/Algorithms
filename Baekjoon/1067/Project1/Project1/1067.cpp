#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);

// FFT �Լ�
void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    // �ε����� �������� ¦����° ��ȣ�� Ȧ����° ��ȣ�� ����
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    // ������������ FFT ����
    fft(a0, invert);
    fft(a1, invert);

    //���Ϸ� ���� ( �ð� ���� => ���ļ� ����)
    double angle = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(angle), sin(angle));

    //Cooley-Tukey �˰���
    for (int i = 0; i < n / 2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) { // ����ȯ�� ���ļ����� => �ð�����
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn; // ��ġ����
    }
}

// ��ȯ ��������� Ȱ���� �ִ� ���� ���
double max_circular_score(int N, vector<int>& X, vector<int>& Y) {
    int sz = 1;
    while (sz < 2 * N) sz *= 2;  // FFT�� ���� ũ�� ���� (2N �̻�)

    vector<cd> A(sz), B(sz);

    // X�� �� ��� Ȯ���Ͽ� ��ȯ ������� ����
    for (int i = 0; i < N; i++) {
        A[i] = X[i];
        A[i + N] = X[i]; // X�� 2��� Ȯ��
        B[i] = Y[N - i - 1]; // Y�� ������ (��ȯ ������� ����)
    }

    // FFT ����
    fft(A, false);
    fft(B, false);

    // A�� B�� �� (������� ����)
    for (int i = 0; i < sz; i++) {
        A[i] *= B[i];
    }

    // �� FFT ����
    fft(A, true);

    // �ִ� ���� �� ã��
    double result = 0;
    for (int i = 0; i < N; i++) {
        result = max(result, real(A[i + N - 1]));  // ��Ȯ�� ��ġ���� �ִ밪 ã��
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

    // ��ȯ ��������� ���� �ִ� ���� ���
    cout << (long long)(max_circular_score(N, X, Y) + 0.5) << endl;  // �ݿø�

    return 0;
}
