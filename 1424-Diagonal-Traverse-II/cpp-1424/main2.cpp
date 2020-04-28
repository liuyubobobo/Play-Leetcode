/// Source : https://leetcode.com/problems/diagonal-traverse-ii/
/// Author : liuyubobobo
/// Time   : 2020-04-25

#include <iostream>
#include <vector>

using namespace std;


/// Using Bucket
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        vector<vector<int>> buckets;
        for(int i = 0; i < nums.size(); i ++)
            for(int j = 0; j < nums[i].size(); j ++){
                if(i + j >= buckets.size()) buckets.push_back({});
                buckets[i + j].push_back(nums[i][j]);
            }

        vector<int> res;
        for(const vector<int>& v: buckets)
            for(int i = v.size() - 1; i >= 0; i --) res.push_back(v[i]);
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    print_vec(Solution().findDiagonalOrder(nums));

    return 0;
}
