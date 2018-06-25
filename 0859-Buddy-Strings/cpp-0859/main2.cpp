/// Source : https://leetcode.com/problems/buddy-strings/description/
/// Author : liuyubobobo
/// Time   : 2018-06-25

#include <iostream>

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
        return A[first] == B[second] && A[second] == B[first];
    }

private:
    bool atLeastTwoSame(const string& s){
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for(char c: s){
            freq[c - 'a'] ++;
            if(freq[c - 'a'] >= 2)
                return true;
        }
        return false;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    print_bool(Solution().buddyStrings("ab", "ba")); // true
    print_bool(Solution().buddyStrings("ab", "ab")); // false
    print_bool(Solution().buddyStrings("ab", "ba")); // true
    print_bool(Solution().buddyStrings("aaaaaaabc", "aaaaaaacb")); // true
    print_bool(Solution().buddyStrings("", "aa")); // false

    return 0;
}