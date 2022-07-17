/// Source : https://leetcode.com/problems/maximum-number-of-pairs-in-array/
/// Author : liuyubobobo
/// Time   : 2022-07-16

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {

        map<int, int> f;
        for(int e: nums) f[e] ++;

        vector<int> res(2, 0);
        for(const pair<int, int>& p: f){
            res[0] += p.second / 2;
            res[1] += p.second % 2;
        }
        return res;
    }
};


int main() {

    return 0;
}
