/// Source : https://leetcode.com/problems/divide-array-into-equal-pairs/
/// Author : liuyubobobo
/// Time   : 2022-03-19

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool divideArray(vector<int>& nums) {

        unordered_map<int, int> f;
        for(int e: nums) f[e] ++;

        for(const pair<int, int>& p: f)
            if(p.second % 2) return false;
        return true;
    }
};


int main() {

    return 0;
}
