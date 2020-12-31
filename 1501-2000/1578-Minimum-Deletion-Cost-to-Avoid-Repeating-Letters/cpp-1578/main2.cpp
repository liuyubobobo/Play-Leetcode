/// Source : https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
/// Author : liuyubobobo
/// Time   : 2020-10-17

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minCost(string s, vector<int>& cost) {

        int res = 0;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){
                res += accumulate(cost.begin() + start, cost.begin() + i, 0) - *max_element(cost.begin() + start, cost.begin() + i);
                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    vector<int> cost1 = {1,2,3,4,5};
    cout << Solution().minCost("abaac", cost1) << endl;
    // 3

    vector<int> cost2 = {1,2,3};
    cout << Solution().minCost("abc", cost2) << endl;
    // 0

    vector<int> cost3 = {1,2,3, 4, 1};
    cout << Solution().minCost("aabaa", cost3) << endl;
    // 2

    return 0;
}
