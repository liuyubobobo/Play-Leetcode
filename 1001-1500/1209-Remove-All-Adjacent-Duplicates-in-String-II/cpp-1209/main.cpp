/// Source : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
/// Author : liuyubobobo
/// Time   : 2019-09-28

#include <iostream>
#include <stack>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char, int>> stack;
        for(char c: s){
            if(!stack.empty() && stack.top().first == c)
                stack.top().second ++;
            else
                stack.push(make_pair(c, 1));

            if(stack.top().second == k)
                stack.pop();
        }

        string res = "";
        while(!stack.empty())
            res += string(stack.top().second, stack.top().first), stack.pop();
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    cout << Solution().removeDuplicates("abcd", 2) << endl;
    // abcd

    cout << Solution().removeDuplicates("deeedbbcccbdaa", 3) << endl;
    // aa

    cout << Solution().removeDuplicates("pbbcggttciiippooaais", 2) << endl;
    // ps

    return 0;
}