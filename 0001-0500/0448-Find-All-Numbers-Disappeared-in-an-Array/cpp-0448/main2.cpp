/// Source : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
/// Author : liuyubobobo
/// Time   : 2021-02-12

#include <iostream>
#include <vector>

using namespace std;


/// Using elements as index
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        for(int i = 0; i < nums.size(); )
            if(nums[i] > 0){
                int pos = nums[i] - 1;
                if(nums[pos] < 0) i ++;
                else{
                    swap(nums[pos], nums[i]);
                    nums[pos] = -nums[pos];
                }
            }
            else i ++;

        vector<int> res;
        for(int i = 0; i < nums.size(); i ++)
            if(nums[i] > 0) res.push_back(i + 1);
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    print_vec(Solution().findDisappearedNumbers(nums1));

    return 0;
}
