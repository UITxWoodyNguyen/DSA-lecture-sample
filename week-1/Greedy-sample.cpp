#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void generateSubsetProduct(const int a[], int n, int index, long long currentProduct, bool isEmpty, long long& maxProduct) {
    if (index == n) {
        if (!isEmpty) maxProduct = max(maxProduct, currentProduct);
        return;
    }

    generateSubsetProduct(a, n, index + 1, currentProduct * a[index], false, maxProduct);
    generateSubsetProduct(a, n, index + 1, currentProduct, isEmpty, maxProduct);
}

long long rawMaxSubsetProduct(const int a[], int n) {
    long long maxProduct = LLONG_MIN;
    generateSubsetProduct(a, n, 0, 1, true, maxProduct);
    return maxProduct;
}

long long greedyMaxSubsetProduct(const int a[], int n) {
    if (n == 1) return a[0];

    int cntZero = 0;
    int cntNegative = 0;
    long long product = 1;
    int maxNegative = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) cntZero++;
        else {
            product *= a[i];
            if (a[i] < 0) {
                cntNegative++;
                maxNegative = max(maxNegative, a[i]);
            }
        }
    }

    if ((cntZero == n) || (cntNegative == 1 && cntZero == n - 1)) return 0;
    if (cntNegative & 1) product /= maxNegative;
    return product;
}

int main() {
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "Brute force: " << rawMaxSubsetProduct(a, n) << endl;
    cout << "Greedy: " << greedyMaxSubsetProduct(a, n) << endl;
    return 0;
}