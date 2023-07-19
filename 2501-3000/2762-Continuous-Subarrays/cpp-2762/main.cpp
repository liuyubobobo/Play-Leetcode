/// Source : https://leetcode.com/problems/continuous-subarrays/description/
/// Author : liuyubobobo
/// Time   : 2023-07-10

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        int n = nums.size();
        int l = 0, r = -1;
        map<int, int> f;
        long long res = 0;
        while(l < n){
            if(r + 1 < n && (f.empty() || max_diff(nums[r + 1], f) <= 2))
                f[nums[++ r]] ++, res += (r - l + 1);
            else{
                f[nums[l]] --;
                if(f[nums[l]] == 0)
                    f.erase(nums[l]);
                l ++;
            }
        }
        return res;
    }

private:
    int max_diff(int e, const map<int, int>& f){
        int a = abs(e - f.begin()->first);
        int b = abs(e - f.rbegin()->first);
        return max(a, b);
    }
};


int main() {

    return 0;
}
