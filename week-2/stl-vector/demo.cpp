#include <iostream>
#include <string>
#include "c_vector.hpp"

using namespace std;

void printVector(const c_vector<int>& v, const string& label) {
    cout << label << ": ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << " (size=" << v.size() << ", capacity=" << v.capacity() << ")" << endl;
}

int main() {
    c_vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    printVector(v, "After push_back 10,20,30");

    v.insert(1, 15);
    printVector(v, "After insert(1, 15)");

    v[0] = 5;
    printVector(v, "After v[0] = 5");

    v.erase(2);
    printVector(v, "After erase(2)");

    v.pop_back();
    printVector(v, "After pop_back");

    c_vector<int> v2 = v;
    printVector(v2, "Copy v2 = v");

    v2.push_back(99);
    printVector(v2, "v2 after push_back 99");
    printVector(v, "v unchanged");

    v2.swap(v);
    printVector(v, "After swap, v");
    printVector(v2, "After swap, v2");

    v.clear();
    printVector(v, "After clear");

    c_vector<string> vs;
    vs.push_back("hello");
    vs.push_back("world");
    cout << "String vector: ";
    for (int i = 0; i < vs.size(); ++i) cout << vs[i] << " ";
    cout << endl;

    return 0;
}