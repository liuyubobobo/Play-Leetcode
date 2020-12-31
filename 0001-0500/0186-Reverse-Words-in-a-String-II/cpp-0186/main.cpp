/// Source : https://leetcode.com/problems/reverse-words-in-a-string-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-08-12

#include <iostream>
#include <vector>

using namespace std;

/// Using a Stack to reverse the input
/// Time Complexity: O(len(s))
/// Space Complexity: O(len(s))
class Solution {
public:
    void reverseWords(vector<char>& str) {

        vector<string> stack;
        int start = 0;
        string cur = "";
        for(int i = start; i <= str.size() ;)
            if(i == str.size() || str[i] == ' '){
                stack.push_back(cur);
                start = i + 1;
                i = start;
                cur = "";
            }
            else
                cur += str[i++];

        int index = 0;
        for(int i = stack.size() - 1; i >= 0 ; i --){
            for(int j = 0; j < stack[i].size() ; j ++)
                str[index++] = stack[i][j];
            if(i > 0)
                str[index++] = ' ';
        }
    }
};


void print_vec(const vector<char>& vec){
    for(char c: vec)
        cout << c << " ";
    cout << endl;
}

int main() {

    vector<char> str1 = {'t', 'h', 'e', ' ',
                         's', 'k', 'y', ' ',
                         'i', 's', ' ',
                         'b', 'l', 'u', 'e'};
    Solution().reverseWords(str1);
    print_vec(str1);

    return 0;
}