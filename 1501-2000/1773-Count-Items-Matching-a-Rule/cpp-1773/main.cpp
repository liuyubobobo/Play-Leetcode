/// Source : https://leetcode.com/problems/count-items-matching-a-rule/
/// Author : liuyubobobo
/// Time   : 2021-02-27

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {

        int type = 0;
        if(ruleKey == "color") type = 1;
        else if(ruleKey == "name") type = 2;

        int res = 0;
        for(const vector<string>& v: items)
            res += v[type] == ruleValue;
        return res;
    }
};


int main() {

    return 0;
}
