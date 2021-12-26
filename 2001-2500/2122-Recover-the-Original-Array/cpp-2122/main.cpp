/// Source : https://leetcode.com/problems/recover-the-original-array/
/// Author : liuyubobobo
/// Time   : 2021-12-25

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Compelxity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {

        int n2 = nums.size(), n = n2 / 2;

        sort(nums.begin(), nums.end());
        for(int i = 1; i < n2; i ++){
            vector<int> res = solve(nums, i);
            if(!res.empty()) return res;
        }
        return {};
    }

private:
    vector<int> solve(const vector<int>& nums, int right){

        int r = nums[right] - nums[0];
        if(r == 0 || r % 2) return {};

        int k = r / 2;

        multiset<int> set;
        for(int e: nums) set.insert(e);
        vector<int> res;
        while(!set.empty()){
            int a = *set.begin();
            if(set.count(a + 2 * k)){
                res.push_back(a + k);
                set.erase(set.begin());
                set.erase(set.find(a + 2 * k));
            }
            else return {};
        }
        return res;
    }
};


int main() {

    return 0;
}
