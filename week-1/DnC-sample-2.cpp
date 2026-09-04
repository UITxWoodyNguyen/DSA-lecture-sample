#include <iostream>
using namespace std;

int power(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    if (n & 1) return x * power(x, n - 1);
    int temp = power(x, n / 2);
    return temp * temp;
}

int rawPower(int x, int n) {
    int result = 1;
    while (n) {
        if (n & 1) result *= x;
        x *= x;
        n /= 2;
    }
    return result;
}

int main() {
    int x, n;
    cin >> x >> n;

    cout << power(x, n) << endl;
    cout << rawPower(x, n) << endl;
}