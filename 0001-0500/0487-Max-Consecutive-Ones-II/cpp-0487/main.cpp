/// Source : https://leetcode.com/problems/max-consecutive-ones-ii/
/// Author : liuyubobobo
/// Time   : 2022-10-29

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();

        int res = 0;
        vector<pair<int, int>> v;
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || nums[i] != nums[start]){
                v.push_back({nums[start], i - start});
                if(nums[start]) res = max(res, i - start);
                else res = max(res, 1);
                start = i;
            }

        for(int i = 0; i < v.size(); i ++)
            if(v[i].first == 1 && (i - 1 >= 0 || i + 1 < v.size()))
                res = max(res, v[i].second + 1);

        for(int i = 0; i < v.size(); i ++)
            if(v[i].first == 0 && v[i].second == 1){
                int t = 1;
                if(i - 1 >= 0) t += v[i - 1].second;
                if(i + 1 < v.size()) t += v[i + 1].second;
                res = max(res, t);
            }
        return res;
    }
};


int main() {

    return 0;
}
