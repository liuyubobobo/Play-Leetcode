/// Source : https://leetcode.com/problems/largest-unique-number/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {

        unordered_map<int, int> freq;
        for(int a: A) freq[a] ++;

        int res = -1;
        for(const pair<int, int>& p: freq)
            if(p.second == 1) res = max(res, p.first);
        return res;
    }
};


int main() {
    return 0;
}