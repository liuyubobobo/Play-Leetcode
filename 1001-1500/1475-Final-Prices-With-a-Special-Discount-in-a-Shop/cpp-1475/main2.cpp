/// Source : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        int n = prices.size();

        vector<int> res(n);
        stack<int> stack;
        for(int i = 0; i < n; i ++){
            while(!stack.empty() && prices[i] <= prices[stack.top()])
                res[stack.top()] = prices[stack.top()] - prices[i], stack.pop();
            stack.push(i);
        }
        while (!stack.empty()) res[stack.top()] = prices[stack.top()], stack.pop();
        return res;
    }
};


int main() {

    return 0;
}
