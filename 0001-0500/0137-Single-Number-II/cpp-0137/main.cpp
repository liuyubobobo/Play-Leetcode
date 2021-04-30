/// Source : https://leetcode.com/problems/single-number-ii/
/// Author : liuyubobobo
/// Time   : 2021-04-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> f;
        for(int e: nums) f[e] ++;

        for(const pair<int, int>& p: f)
            if(p.second == 1) return p.first;
        return -1;
    }
};


int main() {

    return 0;
}
