/// Source : https://leetcode.com/problems/number-of-different-integers-in-a-string/
/// Author : liuyubobobo
/// Time   : 2021-03-27

#include <iostream>
#include <unordered_set>

using namespace std;


/// Split and Using HashSet
/// Time Complexity: O(|s|)
/// Space Complexity: O(|s|)
class Solution {
public:
    int numDifferentIntegers(string s) {

        unordered_set<string> set;
        for(int start = next_digit(s, 0), i = start + 1; i <= s.size(); i ++){
            if(i == s.size() || !isdigit(s[i])){

                string x = s.substr(start, i - start);
                while(x.size() && x[0] == '0') x = x.substr(1);
                set.insert(x);

                start = next_digit(s, i);
                i = start;
            }
        }
        return set.size();
    }

private:
    int next_digit(const string& s, int start){
        for(int i = start; i < s.size(); i ++)
            if(isdigit(s[i])) return i;
        return s.size();
    }
};


int main() {

    cout << Solution().numDifferentIntegers("0aoqn2dsforb4pcjcqk4xdkzmqqq7xlixpzpgo7iokycmzpy2z8ya0p5se962r0wseoag9") << endl;
    // 8

    cout << Solution().numDifferentIntegers("uu717761265362523668772526716127260222200144937319826j717761265362523668772526716127260222200144937319826k717761265362523668772526716127260222200144937319826b7177612653625236687725267161272602222001449373198262hgb9utohfvfrxprqva3y5cdfdudf7zuh64mobfr6mhy17") << endl;
    // 9

    return 0;
}
