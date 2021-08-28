/// Source : https://leetcode.com/problems/longest-uncommon-subsequence-i/
/// Author : liuyubobobo
/// Time   : 2021-08-27

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findLUSlength(string a, string b) {

        if(a.size() != b.size()) return max(a.size(), b.size());

        return a == b ? -1 : a.size();
    }
};


int main() {

    return 0;
}
