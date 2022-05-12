/// Source : https://leetcode.cn/problems/one-away-lcci/
/// Author : liuyubobobo
/// Time   : 2022-05-12

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool oneEditAway(string first, string second) {

        int n1 = first.size(), n2 = second.size();
        if(n1 == n2){

            int change = 0;
            for(int i = 0; i < n1; i ++)
                change += (first[i] != second[i]);
            return change <= 1;
        }

        if(abs(n1 - n2) > 1) return false;

        if(n1 > n2) swap(n1, n2), swap(first, second);

        // n1 < n2;
        for(int len = 0; len <= n1; len ++)
            if(first.substr(0, len) == second.substr(0, len) && first.substr(len) == second.substr(len + 1))
                return true;
        return false;
    }
};


int main() {

    return 0;
}
