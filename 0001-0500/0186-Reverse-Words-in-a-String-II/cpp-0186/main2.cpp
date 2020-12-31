/// Source : https://leetcode.com/problems/reverse-words-in-a-string-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-08-12

#include <iostream>
#include <vector>

using namespace std;

/// Reverse and then Reverse
/// Time Complexity: O(len(s))
/// Space Complexity: O(1)
class Solution {
public:
    void reverseWords(vector<char>& str) {

        reverse(str, 0, str.size() - 1);
        int start = 0;
        for(int i = start + 1; i <= str.size() ;)
            if(i == str.size() || str[i] == ' '){
                reverse(str, start, i - 1);
                start = i + 1;
                i = start + 1;
            }
            else
                i ++;
    }

private:
    void reverse(vector<char>& s, int start, int end){
        for(int i = start, j = end; i < j; i ++, j --)
            swap(s[i], s[j]);
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