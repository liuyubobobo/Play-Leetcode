/// Source : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Binary Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {

        int n = chalk.size();
        vector<long long> presum(n + 1, 0ll);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + chalk[i];

        k %= presum.back();
        return upper_bound(presum.begin() + 1, presum.end(), k) - presum.begin() - 1;
    }
};


int main() {

    vector<int> chalk1 = {3, 4, 1, 2};
    cout << Solution().chalkReplacer(chalk1, 25) << endl;
    // 1

    return 0;
}
