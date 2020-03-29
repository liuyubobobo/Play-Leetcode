/// Source : https://leetcode.com/problems/find-lucky-integer-in-an-array/
/// Author : liuyubobobo
/// Time   : 2020-03-28

#include <iostream>
#include <map>
#include <vector>

using namespace std;


/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int findLucky(vector<int>& arr) {

        map<int, int> freq;
        for(int e: arr) freq[e] ++;

        int res = -1;
        for(const pair<int, int>& p: freq)
            if(p.first == p.second) res = max(res, p.first);
        return res;
    }
};


int main() {

    return 0;
}
