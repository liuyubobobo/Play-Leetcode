/// Source : https://leetcode.com/problems/product-of-the-last-k-numbers/
/// Author : liuyubobobo
/// Time   : 2019-02-15

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: add: O(1)
///                  getProduct: O(k)
/// Space Complexity: O(1)
class ProductOfNumbers {

private:
    vector<int> v;

public:
    ProductOfNumbers() {}

    void add(int num) {

        v.push_back(num);
    }

    int getProduct(int k) {

        int res = 1;
        for(int i = v.size() - 1; i >= (int)v.size() - k; i --)
            res *= v[i];
        return res;
    }
};


int main() {

    ProductOfNumbers p;
    p.add(1);
    cout << p.getProduct(1) << endl;

    return 0;
}
