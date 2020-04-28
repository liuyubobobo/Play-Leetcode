/// Source : https://leetcode.com/problems/diagonal-traverse-ii/
/// Author : liuyubobobo
/// Time   : 2020-04-25

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        vector<pair<pair<int, int>, int>> v;
        for(int i = 0; i < nums.size(); i ++)
            for(int j = 0; j < nums[i].size(); j ++)
                v.push_back(make_pair(make_pair(i, j), nums[i][j]));

        sort(v.begin(), v.end(),
             [](const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2){

            if(p1.first.first + p1.first.second != p2.first.first + p2.first.second)
                return p1.first.first + p1.first.second < p2.first.first + p2.first.second;
            return p1.first.first > p2.first.first;
        });

        vector<int> res;
        for(const pair<pair<int, int>, int>& p: v) res.push_back(p.second);
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
