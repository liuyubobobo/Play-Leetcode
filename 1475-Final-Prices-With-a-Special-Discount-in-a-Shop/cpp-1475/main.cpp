/// Source : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        int n = prices.size();

        vector<int> res(n, 0);
        res[n - 1] = prices[n - 1];
        for(int i = n - 2; i >= 0; i --){
            res[i] = prices[i];
            for(int j = i + 1; j < n; j ++)
                if(prices[j] <= prices[i]){
                    res[i] -= prices[j];
                    break;
                }
        }
        return res;
    }
};


int main() {

    return 0;
}
