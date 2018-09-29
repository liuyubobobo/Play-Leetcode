/// Source : https://leetcode.com/problems/decode-string/description/
/// Author : liuyubobobo
/// Time   : 2018-09-29

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


/// Using Stack - non recursion algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string decodeString(string s) {

        vector<string> stack;
        vector<int> nums;

        stack.push_back("");
        for(int i = 0; i < s.size();)
            if(isalpha(s[i]))
                stack.back() += s[i ++];
            else if(isdigit(s[i])){
                int j;
                for(j = i + 1; j < s.size() && isdigit(s[j]); j ++);
                nums.push_back(atoi(s.substr(i, j - i).c_str()));
                stack.push_back("");
                assert(s[j] == '[');
                i = j + 1;
            }
            else{
                assert(s[i] == ']');
                string tres = stack.back();
                stack.pop_back();

                int num = nums.back();
                nums.pop_back();

                while(num --)
                    stack.back() += tres;

                i ++;
            }
        return stack.back();
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