/// Source : https://leetcode.com/problems/shifting-letters-ii/
/// Author : liuyubobobo
/// Time   : 2022-08-20

#include <iostream>
#include <vector>

using namespace std;


/// Diff Array
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.size();
        vector<int> diff_array(n + 1, 0);
        for(const vector<int>& shift: shifts){
            int start = shift[0], end = shift[1], d = shift[2];
            if(d == 0) d = -1;
            diff_array[start] += d, diff_array[end + 1] -= d;
        }

        string res = "";
        int cur = 0;
        for(int i = 0; i < n; i ++){
            cur += diff_array[i];

            int d = cur;
            if(d < 0) d = d % 26 + 26;
            else d %= 26;

            int c = (s[i] - 'a' + d) % 26;
            res += (char)('a' + c);
        }
        return res;
    }
};


int main() {

    return 0;
}
