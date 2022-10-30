/// Source : https://leetcode.com/problems/destroy-sequential-targets/
/// Author : liuyubobobo
/// Time   : 2022-10-30

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {

        map<int, int> f;
        map<int, int> min_res;
        for(int e: nums){
            f[e % space] ++;

            if(min_res.count(e % space)) min_res[e % space] = min(min_res[e % space], e);
            else min_res[e % space] = e;
        }

        int maxf = 0;
        for(const pair<int, int>& p: f)
            maxf = max(maxf, p.second);

        int res = INT_MAX;
        for(const pair<int, int>& p: f)
            if(p.second == maxf)
                res = min(res, min_res[p.first]);

        return res;
    }
};


int main() {

    vector<int> nums1 = {3,7,8,1,1,5};
    cout << Solution().destroyTargets(nums1, 2) << '\n';

    return 0;
}
