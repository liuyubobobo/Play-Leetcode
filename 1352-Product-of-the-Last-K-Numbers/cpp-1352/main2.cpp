/// Source : https://leetcode.com/problems/product-of-the-last-k-numbers/
/// Author : liuyubobobo
/// Time   : 2019-02-17

#include <iostream>
#include <vector>

using namespace std;


/// Prefix Product
/// Time Complexity: add: O(1)
///                  getProduct: O(1)
/// Space Complexity: O(n)
class ProductOfNumbers {

private:
    vector<int> pre;

public:
    ProductOfNumbers() {}

    void add(int num) {

        if(!num) pre = {1};
        else pre.push_back(pre.back() * num);
    }

    int getProduct(int k) {
        return k + 1 <= pre.size() ? pre.back() / pre[pre.size() - k - 1] : 0;
    }
};


int main() {

    ProductOfNumbers p;
    p.add(1);
    cout << p.getProduct(1) << endl;

    return 0;
}
