/// Source : https://leetcode.com/problems/buddy-strings/description/
/// Author : liuyubobobo
/// Time   : 2018-06-23

#include <iostream>
#include <unordered_map>

using namespace std;

/// Scan and Compare
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool buddyStrings(string A, string B) {

        if(A.size() != B.size())
            return false;

        unordered_map<char, char> diff;
        int diff_num = 0;
        for(int i = 0 ; i < A.size() ; i ++)
            if(A[i] != B[i]){
                diff[A[i]] = B[i];
                diff_num ++;
            }

        if(diff_num == 0)
            return atLeastTwoSame(A);

        if(diff_num != 2)
            return false;

        unordered_map<char, char>::iterator iter1 = diff.begin();
        unordered_map<char, char>::iterator iter2 = diff.begin();
        iter2 ++;
        return iter1->first == iter2->second && iter1->second == iter2->first;
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