/// Source : https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/
/// Author : liuyubobobo
/// Time   : 2022-01-29

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Sufsum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {

        int n = nums.size();

        vector<int> pre0(n + 1, 0);
        for(int i = 0; i < n; i ++) pre0[i + 1] = pre0[i] + (nums[i] == 0);

        vector<int> suf1(n + 1, 0);
        for(int i = n - 1; i >= 0; i --) suf1[i] = suf1[i + 1] + (nums[i] == 1);

        int max_score = -1;
        vector<int> res;
        for(int i = 0; i <= n; i ++){
            int score = pre0[i] + suf1[i];
            if(score > max_score){
                max_score = score; res = {i};
            }
            else if(score == max_score) res.push_back(i);
        }

        return res;
    }
};


int main() {

    return 0;
}
