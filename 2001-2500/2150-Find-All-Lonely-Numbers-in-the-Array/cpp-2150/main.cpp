/// Source : https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
/// Author : liuyubobobo
/// Time   : 2022-01-22

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {

        map<int, int> f;
        for(int e: nums) f[e] ++;

        vector<int> res;
        for(const pair<int, int>& p: f)
            if(p.second == 1 && !f.count(p.first - 1) && !f.count(p.first + 1))
                res.push_back(p.first);
        return res;
    }
};


int main() {

    return 0;
}
