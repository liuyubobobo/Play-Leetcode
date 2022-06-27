/// Source : https://leetcode.com/problems/wiggle-sort-ii/
/// Author : liuyubobobo
/// Time   : 2022-06-27

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> res(n);
        int index = 0;
        for(int i = 0; i < n; i += 2) res[i] = nums[index ++];
        for(int i = 1; i < n; i += 2) res[i] = nums[index ++];

        if(ok(n, res)){
            nums = res;
            return;
        }

        assert(n % 2 == 0);

        index = 0;
        for(int i = 1; i < n; i += 2) res[i] = nums[index ++];
        for(int i = 0; i < n; i += 2) res[i] = nums[index ++];
        reverse(res.begin(), res.end());
        assert(ok(n, res));
        nums = res;
    }

private:
    bool ok(int n, const vector<int>& a){

        for(int i = 1; i + 1 < n; i ++){
            if(i % 2 == 1){
                if(!(a[i - 1] < a[i] && a[i] > a[i + 1])) return false;
            }
            else{
                if(!(a[i - 1] > a[i] && a[i] < a[i + 1])) return false;
            }
        }
        return true;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> nums1 = {4, 5, 5, 6};
    Solution().wiggleSort(nums1);
    print_vec(nums1);

    return 0;
}
