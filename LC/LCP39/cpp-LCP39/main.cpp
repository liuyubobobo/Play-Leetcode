/// Source : https://leetcode-cn.com/problems/0jQkd0/
/// Author : liuyubobobo
/// Time   : 2021-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(max_num)
class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {

        vector<int> f1(10001, 0), f2(10001, 0);
        for(int i = 0; i < source.size(); i ++)
            for(int j = 0; j < source[i].size(); j ++){
                f1[source[i][j]] ++;
                f2[target[i][j]] ++;
            }

        int res = 0;
        for(int i = 0; i < f1.size(); i ++)
            res += abs(f1[i] - f2[i]);
        return res / 2 + res % 2;
    }
};


int main() {

    vector<vector<int>> source1 = {{1, 3}, {5, 4}}, target1 = {{3, 1}, {6, 5}};
    cout << Solution().minimumSwitchingTimes(source1, target1) << endl;
    // 1

    vector<vector<int>> source2 = {{1, 2, 3}, {3, 4, 5}}, target2 = {{1, 3, 5}, {2, 3, 4}};
    cout << Solution().minimumSwitchingTimes(source2, target2) << endl;
    // 0

    return 0;
}
