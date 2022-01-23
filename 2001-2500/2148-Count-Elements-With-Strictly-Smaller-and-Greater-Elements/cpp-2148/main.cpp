/// Source : https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
/// Author : liuyubobobo
/// Time   : 2022-01-22

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countElements(vector<int>& nums) {

        map<int, int> f;
        for(int e: nums) f[e] ++;

        int res = 0;
        for(const pair<int, int>& p: f)
            if(p.first != f.begin()->first && p.first != f.rbegin()->first)
                res += p.second;
        return res;
    }
};


int main() {

    return 0;
}
