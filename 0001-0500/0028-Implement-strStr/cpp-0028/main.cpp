/// Source : https://leetcode.com/problems/implement-strstr/
/// Author : liuyubobobo
/// Time   : 2018-03-06

#include <iostream>

using namespace std;


/// Naive implementation
/// Time Complexity: O(n * m)
/// Sapce Complexity: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size(), m = needle.size();
        for(int i = 0 ; i <= n - m ; i ++){
            int j = 0;
            for(j = 0 ; j < needle.size() ; j ++)
                if(needle[j] != haystack[j + i])
                    break;
            if(j == needle.size())
                return i;
        }
        return -1;
    }
};


int main() {

    cout << Solution().strStr("hello", "ll") << endl;
    cout << Solution().strStr("aaaaa", "bba") << endl;

    return 0;
}