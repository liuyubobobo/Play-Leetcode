/// Source : https://leetcode.com/problems/find-all-duplicates-in-an-array/
/// Author : liuyubobobo
/// Time   : 2021-10-05

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        map<int, int> f;
        for(int e: nums) f[e] ++;

        vector<int> res;
        for(const pair<int, int>& p: f)
            if(p.second == 2) res.push_back(p.first);
        return res;
    }
};


int main() {

    return 0;
}
