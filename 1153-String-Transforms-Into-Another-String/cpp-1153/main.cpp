/// Source : https://leetcode.com/problems/string-transforms-into-another-string/
/// Author : liuyubobobo
/// Time   : 2019-08-10

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool canConvert(string str1, string str2) {

        if(str1 == str2) return true;

        unordered_map<char, char> map;
        for(int i = 0; i < str1.size(); i ++){
            if(map.count(str1[i]) && map[str1[i]] != str2[i])
                return false;
            map[str1[i]] = str2[i];
        }
        return unordered_set<char>(str2.begin(), str2.end()).size() < 26;
    }
};


int main() {

    cout << Solution().canConvert("aabcc", "ccdee") << endl;
    // 1

    cout << Solution().canConvert("leetcode", "codeleet") << endl;
    // 0

    cout << Solution().canConvert("abcde", "zzzzz") << endl;
    // 1

    return 0;
}