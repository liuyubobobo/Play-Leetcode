/// Source : https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
/// Author : liuyubobobo
/// Time   : 2022-01-01

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkString(string s) {

        int lasta = -1, firstb = s.size();
        for(int i = 0; i < s.size(); i ++)
            if(s[i] == 'a') lasta = max(lasta, i);
            else firstb = min(firstb, i);
        return lasta < firstb;
    }
};


int main() {

    return 0;
}
