/// Source : https://leetcode.com/problems/number-of-substrings-with-fixed-ratio/description/
/// Author : liuyubobobo
/// Time   : 2022-12-19

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {

        int n = s.size();
        vector<int> presum1(n + 1, 0);
        for(int i = 0; i < n; i ++) presum1[i + 1] = presum1[i] + (s[i] == '1');

        long long res = 0;
        map<int, int> table;
        table[0] = 1;
        for(int i = 0; i < n; i ++){
            int t = presum1[i + 1] * num1 - (i + 1 - presum1[i + 1]) * num2;
            auto iter = table.find(t);
            if(iter != table.end()) res += iter->second;
            table[t] ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
