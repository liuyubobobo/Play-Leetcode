/// Source : https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/
/// Author : liuyubobobo
/// Time   : 2023-05-06

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(q)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {

        vector<int> nums(n, 0);
        int cur = 0;
        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            int index = queries[i][0], c = queries[i][1];
            int old_color = nums[index];
            if(c == old_color){
                res[i] = cur; continue;
            }

            nums[index] = c;
            if(old_color){
                if(index - 1 >= 0 && nums[index - 1] == old_color) cur --;
                if(index + 1 < n && nums[index + 1] == old_color) cur --;
            }

            if(index - 1 >= 0 && nums[index - 1] == c) cur ++;
            if(index + 1 < n && nums[index + 1] == c) cur ++;

            res[i] = cur;
        }
        return res;
    }
};


int main() {

    return 0;
}
