/// Source : https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
/// Author : liuyubobobo
/// Time   : 2021-02-13

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minOperations(string s) {

        int res = INT_MAX;

        string s1(s.size(), '0');
        for(int i = 0; i < s1.size(); i += 2)
            s1[i] = '1';
        res = min(res, diff(s, s1));

        string s2(s.size(), '0');
        for(int i = 1; i < s2.size(); i += 2)
            s2[i] = '1';
        res = min(res, diff(s, s2));

        return res;
    }

private:
    int diff(const string& s1, const string& s2){

        int res = 0;
        for(int i = 0; i < s1.size(); i ++)
            res += (s1[i] != s2[i]);
        return res;
    }
};


int main() {

    return 0;
}
