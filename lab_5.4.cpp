#include <iostream>
#include <cmath>

using namespace std;

// Допоміжна функція для обчислення k-го члена
double term(int k, int N) {
    double k2 = 1.0 * k * k;
    double N2 = 1.0 * N * N;
    return (k2 / N2) * cos(N2 / k2);
}

// 0) Ітераційний спосіб (для контролю)
double P0(const int N) {
    double p = 1.0;
    for (int k = 1; k <= N; k++) {
        p *= term(k, N);
    }
    return p;
}

// 1) Рекурсивний підйом, параметр зростає (k від 1 до N)
double P1(const int N, const int k) {
    if (k > N)
        return 1.0;
    else
        return term(k, N) * P1(N, k + 1);
}

// 2) Рекурсивний підйом, параметр спадає (k від N до 1)
double P2(const int N, const int k) {
    if (k < 1)
        return 1.0;
    else
        return term(k, N) * P2(N, k - 1);
}

// 3) Рекурсивний спуск, параметр зростає (k від 1 до N)
double P3(const int N, const int k, double t) {
    t = t * term(k, N);
    if (k >= N)
        return t;
    else
        return P3(N, k + 1, t);
}

// 4) Рекурсивний спуск, параметр спадає (k від N до 1)
double P4(const int N, const int k, double t) {
    t = t * term(k, N);
    if (k <= 1)
        return t;
    else
        return P4(N, k - 1, t);
}

int main() {
    int N;
    cout << "N = ";
    cin >> N;

    cout << "(iter) P0 = " << P0(N) << endl;
    cout << "(rec up ++) P1 = " << P1(N, 1) << endl;
    cout << "(rec up --) P2 = " << P2(N, N) << endl;
    cout << "(rec down ++) P3 = " << P3(N, 1, 1.0) << endl;
    cout << "(rec down --) P4 = " << P4(N, N, 1.0) << endl;

    return 0;
}
