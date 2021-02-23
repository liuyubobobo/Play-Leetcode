/// Source : https://leetcode.com/problems/grumpy-bookstore-owner/
/// Author : liuyubobobo
/// Time   : 2021-02-22

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {

        int cur = 0, maxv = 0, sum = 0;
        for(int i = 0; i + 1 < X; i ++){
            cur += grumpy[i] * customers[i];
            sum += (1 - grumpy[i]) * customers[i];
        }

        for(int i = X - 1; i < customers.size(); i ++){
            cur += customers[i] * grumpy[i];
            sum += (1 - grumpy[i]) * customers[i];
            maxv = max(maxv, cur);
            cur -= customers[i - (X - 1)] * grumpy[i - (X - 1)];
        }

        return sum + maxv;
    }
};


int main() {

    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy =    {0, 1, 0, 1, 0, 1, 0, 1};
    cout << Solution().maxSatisfied(customers, grumpy, 3) << endl;
    // 16

    return 0;
}
