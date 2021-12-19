/// Source : https://leetcode.com/problems/decode-string/description/
/// Author : liuyubobobo
/// Time   : 2021-12-19

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>

using namespace std;


/// DFS - recursion algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string decodeString(string s) {

        int n = s.size();

        // ends[i] 表示如果 s[i] == '[', 其对应的 ']' 的位置
        vector<int> ends(n, -1);
        stack<int> stack;
        for(int i = 0; i < n; i ++) {
            if (s[i] == '[') stack.push(i);
            else if (s[i] == ']') ends[stack.top()] = i, stack.pop();
        }

        return dfs(s, 0, n - 1, ends);
    }

private:
    string dfs(const string& s, int l, int r, const vector<int>& ends){

        if(l > r) return "";

        // 如果 s[l] 是字符，则可以直接处理后面
        if(isalpha(s[l])) return string(1, s[l]) + dfs(s, l + 1, r, ends);

        // 否则 s[l] 一定是数字
        assert(isdigit(s[l]));
        int num = 0, i; // num 是当前完整的数字（数字可能多位）
        for(i = l; isdigit(s[i]); i ++)
            num = num * 10 + (s[i] - '0');

        // 数字最后一位的后一个字符一定是 '['
        assert(s[i] == '[');
        string res = "";
        string t = dfs(s, i + 1, ends[i] - 1, ends); // 递归求出 [] 中的字符串
        while(num --) res += t; // 这个字符串重复 num 次

        // 如果 ']' 后续还有未处理的字符，则继续递归处理
        if(ends[i] + 1 <= r) res += dfs(s, ends[i] + 1, r, ends);

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