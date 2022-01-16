/// Source : https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
/// Author : liuyubobobo
/// Time   : 2022-01-15

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        vector<string> res;
        for(int i = 0; i < s.size(); i += k)
            res.push_back(s.substr(i, k));
        while(res.back().size() != k) res.back() += fill;
        return res;
    }
};


int main() {

    Solution().divideString("abcdefghi", 3, 'x');

    return 0;
}
