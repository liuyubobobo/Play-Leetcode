/// Source : https://leetcode.com/problems/check-if-a-string-can-break-another-string/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {

        int n = s1.size();

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int i = 0;
        for(i = 0; i < n; i ++) if(s1[i] < s2[i]) break;
        if(i == n) return true;

        i = 0;
        for(i = 0; i < n; i ++) if(s2[i] < s1[i]) break;
        if(i == n) return true;

        return false;
    }
};


int main() {

    cout << Solution().checkIfCanBreak("abc", "xya") << endl;
    // 1

    cout << Solution().checkIfCanBreak("abe", "acd") << endl;
    // 0

    cout << Solution().checkIfCanBreak("leetcodee", "interview") << endl;
    // 1

    return 0;
}
