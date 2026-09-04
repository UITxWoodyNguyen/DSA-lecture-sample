#include <iostream>
using namespace std;

class solution {
    int n, fibo[1000];

    public:
        void input() {
            cin >> n;
        }

        void GenerateFibo() {
            fibo[0] = 0;
            fibo[1] = 1;
            for (int i = 2; i <= n; i++) {
                fibo[i] = fibo[i - 1] + fibo[i - 2];
            }
        }

        int getFibo(int index) {
            return fibo[index];
        }
};

int main () {
    solution s;
    s.input();
    s.GenerateFibo();

    int ind;
    cin >> ind;
    cout << s.getFibo(ind) << endl;
}