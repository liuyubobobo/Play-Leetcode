/// Source : https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/description/
/// Author : liuyubobobo
/// Time   : 2023-07-19

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n^2 * logn)
/// Space Complexity: O(n)
class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {


        int n = nums.size();
        int res = 0;
        for(int l = 0; l < n; l ++){
            map<int, int> f;
            int cnt = 0;
            for(int r = l; r < n; r ++){
                f[nums[r]] ++;
                if(r == l) continue;

                auto cur_iter = f.find(nums[r]);
                if(cur_iter->second > 1){
                    res += cnt; continue;
                }
                auto next_iter = cur_iter; next_iter ++;

                if(cur_iter == f.begin()){
                    int next_value = next_iter->first;
                    if(next_value - nums[r] > 1) cnt ++;
                }
                else if(next_iter == f.end()){
                    auto pre_iter = cur_iter; pre_iter --;
                    int pre_value = pre_iter->first;
                    if(nums[r] - pre_value > 1) cnt ++;
                }
                else{
                    auto pre_iter = cur_iter; pre_iter --;
                    int pre_value = pre_iter->first, next_value = next_iter->first;
                    if(next_value - pre_value > 1) cnt --;
                    if(nums[r] - pre_value > 1) cnt ++;
                    if(next_value - nums[r] > 1) cnt ++;
                }
                res += cnt;
            }
        }
        return res;
    }
};

int main() {

    vector<int> nums2 = {1, 3, 3, 3, 5};
    cout << Solution().sumImbalanceNumbers(nums2) << '\n';
    // 8

    return 0;
}
