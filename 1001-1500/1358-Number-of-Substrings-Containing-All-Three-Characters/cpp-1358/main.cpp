/// Source : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
/// Author : liuyubobobo
/// Time   : 2020-02-23

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();

        vector<int> freq(3, 0);
        int l = 0, r = -1, res = 0;
        while(l < n && r + 1 < n){
            freq[s[++ r] - 'a'] ++;
            while(l < n && freq[0] && freq[1] && freq[2]){
                res += n - r;
                freq[s[l ++] - 'a'] --;
            }
        }
        return res;
    }
};


int main() {

    cout << Solution().numberOfSubstrings("abcabc") << endl;

    return 0;
}
