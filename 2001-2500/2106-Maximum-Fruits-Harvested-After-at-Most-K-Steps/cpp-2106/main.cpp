/// Source : https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
/// Author : liuyubobobo
/// Time   : 2021-12-11

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(max_pos)
/// Space Complexity: O(max_pos)
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

        int max_pos = startPos;
        for(const vector<int>& e: fruits)
            max_pos = max(max_pos, e[0]);

        vector<int> data(max_pos + 1, 0);
        for(const vector<int>& e: fruits)
            data[e[0]] += e[1];

        vector<long long> presum(data.size() + 1, 0);
        for(int i = 0; i < data.size(); i ++)
            presum[i + 1] = presum[i] + data[i];

        long long res = 0;
        for(int i = 0; startPos + i < data.size() && i <= k; i ++) {
            int r = startPos + i;
            int l = startPos;
            if(k - 2 * i > 0) l = max(0, startPos - (k - 2 * i));
            res = max(res, presum[r + 1] - presum[l]);
        }
        for(int i = 0; startPos - i >= 0 && i <= k; i ++){
            int l = startPos - i;
            int r = startPos;
            if(k - 2 * i > 0) r = min(startPos + (k - 2 * i), (int)data.size() - 1);
            res = max(res, presum[r + 1] - presum[l]);
        }
        return res;
    }
};


int main() {

    vector<vector<int>> fruits1 = {{2, 8}, {6, 3}, {8, 6}};
    cout << Solution().maxTotalFruits(fruits1, 5, 4) << endl;
    // 9

    vector<vector<int>> fruits2 = {{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
    cout << Solution().maxTotalFruits(fruits2, 5, 4) << endl;
    // 14

    vector<vector<int>> fruits3 = {{0, 3}, {6, 4}, {8, 5}};
    cout << Solution().maxTotalFruits(fruits3, 3, 2) << endl;
    // 0

    vector<vector<int>> fruits4 = {{200000, 10000}};
    cout << Solution().maxTotalFruits(fruits4, 200000, 0) << endl;
    // 10000

    vector<vector<int>> fruits5 = {{0, 10000}};
    cout << Solution().maxTotalFruits(fruits5, 200000, 200000) << endl;
    // 10000

    return 0;
}
