/// Source : https://leetcode.com/problems/buddy-strings/description/
/// Author : liuyubobobo
/// Time   : 2018-06-25
/// Updated: 2021-11-22

#include <iostream>
#include <vector>

using namespace std;


/// Scan and Compare
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool buddyStrings(string A, string B) {

        if(A.size() != B.size())
            return false;

        if(A == B)
            return atLeastTwoSame(A);

        int first = -1, second = -1;
        for(int i = 0 ; i < A.size(); i++)
            if(A[i] != B[i]){
                if(first == -1)
                    first = i;
                else if(second == -1)
                    second = i;
                else
                    return false;
            }

        return second != -1 && A[first] == B[second] && A[second] == B[first];
    }

private:
    bool atLeastTwoSame(const string& s){
        vector<int> freq(26, 0);
        for(char c: s){
            freq[c - 'a'] ++;
            if(freq[c - 'a'] >= 2)
                return true;
        }
        return false;
    }
};


int main() {

    cout << Solution().buddyStrings("ab", "ba") << endl;
    // 1

    cout << Solution().buddyStrings("ab", "ab") << endl;
    // 0

    cout << Solution().buddyStrings("ab", "ba") << endl;
    // 1

    cout << Solution().buddyStrings("aaaaaaabc", "aaaaaaacb") << endl;
    // 1

    cout << Solution().buddyStrings("", "aa") << endl;
    // 0

    return 0;
}