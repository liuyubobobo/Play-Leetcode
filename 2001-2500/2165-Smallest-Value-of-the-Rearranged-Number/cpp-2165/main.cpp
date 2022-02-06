/// Source : https://leetcode.com/problems/smallest-value-of-the-rearranged-number/
/// Author : liuyubobobo
/// Time   : 2022-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(|num|log|num|)
/// Space Complexity: O(|num|)
class Solution {
public:
    long long smallestNumber(long long num) {

        if(num == 0) return 0;

        if(num > 0){
            string s = to_string(num);
            sort(s.begin(), s.end());

            int non_zero = 0;
            for(;non_zero < s.size() && s[non_zero] == '0'; non_zero ++);
            string res = string(1, s[non_zero]) + s.substr(0, non_zero) + s.substr(non_zero + 1);
            return atoll(res.c_str());
        }

        string s = to_string(num).substr(1);
        sort(s.begin(), s.end(), greater<char>());
        return atoll(s.c_str()) * -1ll;
    }
};


int main() {

    return 0;
}
