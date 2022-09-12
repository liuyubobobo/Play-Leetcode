/// Source : https://leetcode.com/problems/most-frequent-even-element/
/// Author : liuyubobobo
/// Time   : 2022-09-10

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {

        map<int, int> f;
        for(int e: nums)
            if(e % 2 == 0) f[e] ++;

        int res = -1, best_f = 0;
        for(const pair<int, int>& p: f)
            if(p.second > best_f) res = p.first, best_f = p.second;
        return res;
    }
};


int main() {

    return 0;
}
