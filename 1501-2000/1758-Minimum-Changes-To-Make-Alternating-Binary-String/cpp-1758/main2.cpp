/// Source : https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
/// Author : liuyubobobo
/// Time   : 2021-02-13

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minOperations(string s) {

        int res1 = 0, res2 = 0;
        for(int i = 0; i < s.size(); i ++){
            res1 += s[i] != ('0' + i % 2);
            res2 += s[i] == ('0' + i % 2);
        }
        return min(res1, res2);
    }
};


int main() {

    return 0;
}
