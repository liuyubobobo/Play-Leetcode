/// Source : https://leetcode.com/problems/check-if-a-string-can-break-another-string/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>

using namespace std;


/// Using HahsMap and Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {

        int n = s1.size();

        vector<int> set1(26, 0);
        for(char c: s1) set1[c - 'a'] ++;

        vector<int> set2(26, 0);
        for(char c: s2) set2[c - 'a'] ++;

        return cover(set1, set2) || cover(set2, set1);
    }

private:
    bool cover(const vector<int>& set1, const vector<int>& set2){

        int a = 0, b = 0;
        for(int i = 0; i < 26; i ++){
            a += set1[i], b += set2[i];
            if(a < b) return false;
        }
        return true;
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
