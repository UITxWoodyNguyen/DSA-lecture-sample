#include <iostream>
#include <climits>
using namespace std;

class Solution {
    public:
        int n, a[1000], maxProduct;

        void input() {
            cin >> n;
            for(int i = 0; i < n; i++) cin >> a[i];
        }

        void GenerateSubsetProduct(int index, int currentProduct, bool isEmpty) {
            if (index == n) {
                if (!isEmpty) {     // If the subset is not empty, update the maximum product
                    cout << "currentProduct: " << currentProduct << endl;
                    maxProduct = max(maxProduct, currentProduct);
                    return;
                }

                // Choose a[i]
                GenerateSubsetProduct(index + 1, currentProduct * a[index], false);

                // Not choose a[i]
                GenerateSubsetProduct(index + 1, currentProduct, isEmpty);
            }
        }


        // Find the maximum product of any subset with O(2^n) time complexity
        int RawMaxSubsetProduct() {
            maxProduct = INT_MIN;
            GenerateSubsetProduct(0,1,true);
            return maxProduct;
        }

        // Find the maximum product subset using Greedy Algorithm with O(n) time complexity
        int GreedyMaxSubsetProduct() {
            if (n == 1) return a[0];

            int cntZero = 0;
            int cntNegative = 0;
            int product = 1;
            int maxNegative = INT_MIN;

            for (int i = 0; i < n; i++) {
                if (!a[i]) cntZero++;
                else {
                    product *= a[i];
                    if (a[i] < 0) {
                        cntNegative++;
                        maxNegative = max(maxNegative, a[i]);
                    }
                }
            }

            if ((cntZero == n) || (cntNegative == 1 && cntZero == n-1)) return 0;
            if (cntNegative & 1) product /= maxNegative;  // If odd number of negative numbers, remove the largest negative
            return product;
        }
};

int main() {
    Solution sol;
    sol.input();
    // cout << "Brute force: " << sol.RawMaxSubsetProduct() << endl;
    cout << "Greedy: " << sol.GreedyMaxSubsetProduct() << endl;
    return 0;
}