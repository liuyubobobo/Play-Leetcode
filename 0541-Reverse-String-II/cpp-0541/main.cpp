/// Source : https://leetcode.com/problems/reverse-string-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-06-04

#include <iostream>

using namespace std;

/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string reverseStr(string s, int k) {

        for(int i = 0 ; i < s.size() ; i += 2 * k)
            reverse(s, i, i + k);
        return s;
    }

private:
    void reverse(string& s, int i, int j){
        j = min(j, (int)s.size());
        j --;
        while(i < j)
            swap(s[i ++], s[j --]);
    }
};

int main() {

    cout << Solution().reverseStr("abcdefg", 2) << endl;

    return 0;
}