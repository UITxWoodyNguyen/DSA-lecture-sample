#include <iostream>
using namespace std;

void generateFibo(int n, int fibo[]) {
    if (n >= 0) fibo[0] = 0;
    if (n >= 1) fibo[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

int main() {
    int n;
    cin >> n;

    int fibo[1000];
    generateFibo(n, fibo);

    int ind;
    cin >> ind;
    cout << fibo[ind] << endl;
}