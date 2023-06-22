/// Source : https://leetcode.com/problems/count-substrings-without-repeating-character/description/
/// Author : liuyubobobo
/// Time   : 2023-06-22

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfSpecialSubstrings(string s) {

        vector<int> f(26, 0);
        int l = 0, r = -1, res = 0;
        while(l < s.size()){
            if(r + 1 < s.size() && f[s[r + 1] - 'a'] == 0){
                f[s[++ r] - 'a'] ++;
                res += r - l + 1;
            }
            else{
                f[s[l ++] - 'a'] --;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
