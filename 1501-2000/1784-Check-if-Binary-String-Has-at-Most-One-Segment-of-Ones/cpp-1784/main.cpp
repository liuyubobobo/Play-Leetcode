/// Source : https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
/// Author : liuyubobobo
/// Time   : 2021-03-06

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {

        int cnt = 0;
        for(int start = next_one(s, 0), i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == '0'){
                cnt ++;
                start = next_one(s, i);
                i = start;
            }
        return cnt == 1;
    }

private:
    int next_one(const string& s, int start){
        for(int i = start; i < s.size(); i ++)
            if(s[i] == '1') return i;
        return s.size();
    }
};


int main() {

    return 0;
}
