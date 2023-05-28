/// Source : https://leetcode.com/problems/buy-two-chocolates/
/// Author : liuyubobobo
/// Time   : 2023-05-27

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {

        sort(prices.begin(), prices.end());
        int left = money - prices[0] - prices[1];
        return left >= 0 ? left : money;
    }
};


int main() {

    return 0;
}
