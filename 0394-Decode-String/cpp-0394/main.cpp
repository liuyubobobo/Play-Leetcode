/// Source : https://leetcode.com/problems/decode-string/description/
/// Author : liuyubobobo
/// Time   : 2018-09-29

#include <iostream>
#include <cassert>

using namespace std;


/// DFS - recursion algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string decodeString(string s) {
        int end;
        return dfs(s, 0, end);
    }

private:
    string dfs(const string& s, int start, int& end){

        string res = "";
        for(int i = start; i < s.size();)
            if(isalpha(s[i]))
                res += s[i++];
            else if(isdigit(s[i])){
                int j;
                for(j = i + 1; j < s.size() && isdigit(s[j]); j ++);
                int num = atoi(s.substr(i, j - i).c_str());
                assert(s[j] == '[');

                int e;
                string sub = dfs(s, j + 1, e);
                while(num --)
                    res += sub;

                assert(s[e] == ']');
                i = e + 1;
            }
            else{
                assert(s[i] == ']');
                end = i;
                return res;
            }

        end = s.size();
        return res;
    }
};


int main() {

    string s1 = "3[a]2[bc]";
    cout << Solution().decodeString(s1) << endl;
    // "aaabcbc"

    string s2 = "3[a2[c]]";
    cout << Solution().decodeString(s2) << endl;
    // "accaccacc"

    string s3 = "2[abc]3[cd]ef";
    cout << Solution().decodeString(s3) << endl;
    // "abcabccdcdcdef"

    return 0;
}