#include <iostream>
using namespace std;

// Problem: Calculate x^n
class solution {
    public:
        int x,n;
        void input() {
            cin >> x >> n;
        }
        
        // Create with recursion
        int power (int x, int n) {
            if (n == 0) return 1;
            if (n == 1) return x;

            if (n & 1) return x * power(x, n - 1);
            int temp = power(x, n / 2);
            return temp * temp;
        }

        // Create with iteration
        int rawPower(int x, int n) {
            int result = 1;
            while (n) {
                if (n & 1) result *= x;
                x *= x;
                n /= 2;
            }
            return result;
        }
};

int main () {
    solution P;
    P.input();

    cout << P.power(P.x, P.n) << endl;
    cout << P.rawPower(P.x, P.n) << endl;
}