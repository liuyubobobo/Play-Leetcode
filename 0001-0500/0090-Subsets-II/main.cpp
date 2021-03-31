/// Source : https://leetcode.com/problems/subsets-ii/
/// Author : liuyubobobo
/// Time   : 2021-03-21

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Soting and Using set
/// Time Complexity: O(n * 2^n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        set<vector<int>> s;
        for(int state = 0; state < (1 << n); state ++){
            vector<int> t;
            for(int i = 0; i < n; i ++)
                if(state & (1 << i)) t.push_back(nums[i]);
            s.insert(t);
        }
        return vector<vector<int>>(s.begin(), s.end());
    }
};


int main() {

    return 0;
}
