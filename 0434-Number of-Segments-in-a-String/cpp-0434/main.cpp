/// Source : https://leetcode.com/problems/number-of-segments-in-a-string/description/
/// Author : liuyubobobo
/// Time   : 2017-11-04

#include <iostream>
#include <string>

using namespace std;

/// Time Complexity: O(len(s))
/// Space Complexity: O(1)
class Solution {
public:
    int countSegments(string s) {

        int startIndex = nextChar(s, 0);
        if(startIndex == s.size())
            return 0;

        int res = 0;
        for(int start = startIndex, i = start + 1; i <= s.size() ;){
            if(i >= s.size() || s[i] == ' '){
                res ++;
                start = nextChar(s, i);
                i = start + 1;
            }
            else
                i ++;
        }

        return res;
    }

private:
    int nextChar(const string& s, int index){

        if(index >= s.size())
            return index;

        while(s[index] == ' ')
            index ++;
        return index;
    }
};

int main() {

    cout << Solution().countSegments("Hello, my name is John") << endl;

    return 0;
}