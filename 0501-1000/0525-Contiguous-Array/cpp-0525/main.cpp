/// Source : https://leetcode.com/problems/contiguous-array/
/// Author : liuyubobobo
/// Time   : 2020-05-26

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Linear Scan + HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int cur = 0, res = 0;
        unordered_map<int, int> map; // key -> index
        map[cur] = -1;
        for(int i = 0; i < nums.size(); i ++){
            cur += nums[i] ? 1 : -1;
            if(map.count(cur)) res = max(res, i - map[cur]);
            else map[cur] = i;
        }
        return res;
    }
};


int main() {

    return 0;
}
