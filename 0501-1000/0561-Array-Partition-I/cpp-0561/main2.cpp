/// Source : https://leetcode.com/problems/array-partition-i/solution/
/// Author : liuyubobobo
/// Time   : 2018-06-04
/// Updated: 2022-06-15

#include <iostream>
#include <vector>

using namespace std;


/// Counting Sort based
/// Time Complexity: O(n + (maxv - minv))
/// Space Complexity: O(maxv - minv)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        int maxv = *max_element(nums.begin(), nums.end());
        int minv = *min_element(nums.begin(), nums.end());

        vector<int> cnt(maxv - minv + 2, 0);
        int offset = -minv;

        for(int num: nums)
            cnt[num + offset] ++;

        int sum = 0;
        bool minus = false;
        for(int i = 0 ; i < cnt.size(); i ++)
            if(cnt[i]){
                if(minus){
                    cnt[i] --;
                    minus = false;
                }
                sum += cnt[i] / 2 * (i - offset);
                if(cnt[i] % 2){
                    sum += (i - offset);
                    minus = true;
                }
            }
        return sum;
    }
};


int main() {

    vector<int> nums = {1, 4, 3, 2};
    cout << Solution().arrayPairSum(nums) << endl;

    return 0;
}