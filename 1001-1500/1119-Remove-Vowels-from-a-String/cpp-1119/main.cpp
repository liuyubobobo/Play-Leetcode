/// Source : https://leetcode.com/problems/remove-vowels-from-a-string/
/// Author : liuyubobobo
/// Time   : 2019-07-13

#include <iostream>
#include <unordered_set>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string removeVowels(string S) {

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        string res = "";
        for(char c: S)
            if(!vowels.count(c))
                res += c;
        return res;
    }
};


int main() {

    return 0;
}