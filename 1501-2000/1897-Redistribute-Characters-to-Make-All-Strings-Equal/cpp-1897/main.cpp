/// Source : https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(nums_of_characters)
/// Space Complexity: O(1)
class Solution {
public:
    bool makeEqual(vector<string>& words) {

        vector<int> f(26, 0);
        for(const string& word: words)
            for(char c: word)
                f[c - 'a'] ++;

        int n = words.size();
        for(int e: f)
            if(e % n) return false;
        return true;
    }
};


int main() {

    return 0;
}
