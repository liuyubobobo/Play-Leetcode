/// Source : https://leetcode.com/problems/count-binary-substrings/description/
/// Author : liuyubobobo
/// Time   : 2017-10-15

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Time Complexity: O(len(s))
// Space Complexity: O(len(s))
class Solution {
public:
    int countBinarySubstrings(string s) {

        vector<int> cutRes = cut(s);

        int res = 0;
        for(int i = 0 ; i < cutRes.size()-1 ; i ++)
            res += min(cutRes[i], cutRes[i+1]);
        return res;
    }

private:
    vector<int> cut(string s){

        vector<int> res;
        int start = 0;
        for(int i = start + 1; i <= s.size() ; )
            if(i == s.size() || s[i] != s[start]){
                res.push_back(i - start);
                start = i;
                i = start + 1;
            }
            else
                i ++;
        return res;
    }
};

int main() {

    cout << Solution().countBinarySubstrings("00110011") << endl;
    cout << Solution().countBinarySubstrings("10101") << endl;

    return 0;
}