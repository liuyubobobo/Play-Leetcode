/// Source : https://leetcode.com/problems/the-number-of-beautiful-subsets/description/
/// Author : liuyubobobo
/// Time   : 2023-03-26

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


/// Bitwise
/// Time Complexity: O(nlogn + n^2 + 2^n * n)
/// Space Complexity: O(n^2)
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<list<int>> check(n);
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                if(nums[i] + k == nums[j]){
                    check[i].push_back(j);
                }
            }
        }

        int res = 0;
        for(int state = 1; state < (1 << n); state ++){
            bool ok = true;
            for(int i = 0; i < n && ok; i ++){
                if(((state >> i) & 1) && !check[i].empty()){
                    for(int j: check[i]){
                        if((state >> j) & 1){
                            ok = false;
                            break;
                        }
                    }
                }
            }
            res += ok;
        }
        return res;
    }
};


int main() {

    return 0;
}
