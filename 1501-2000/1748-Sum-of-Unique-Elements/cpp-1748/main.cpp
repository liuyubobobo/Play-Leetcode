/// Source : https://leetcode.com/problems/sum-of-unique-elements/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {

        unordered_map<int, int> f;
        for(int e: nums) f[e] ++;

        int res = 0;
        for(const pair<int, int>& p: f)
            if(p.second == 1) res += p.first;
        return res;
    }
};


int main() {

    return 0;
}
