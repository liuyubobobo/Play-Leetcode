/// Source : https://leetcode.com/problems/rearrange-spaces-between-words/
/// Author : liuyubobobo
/// Time   : 2020-09-19

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string reorderSpaces(string text) {

        int spacenum = 0;
        for(char c: text) spacenum += (c == ' ');

        vector<string> words;
        for(int start = nextletter(text, 0), i = start + 1; i <= text.size(); i ++)
            if(i == text.size() || text[i] == ' '){
                words.push_back(text.substr(start, i - start));
                start = nextletter(text, i);
                i = start;
            }

        if(words.size() == 1) return words[0] + string(spacenum, ' ');

        int interval = spacenum / (words.size() - 1);
        string res = "";
        for(int i = 0; i + 1 < words.size(); i ++)
            res += words[i] + string(interval, ' ');
        res += words.back() + string(spacenum % (words.size() - 1), ' ');
        return res;
    }

private:
    int nextletter(const string& s, int start){
        for(int i = start; i < s.size(); i ++)
            if(s[i] != ' ') return i;
        return s.size();
    }
};


int main() {

    string text1 = "  this   is  a sentence ";
    cout << Solution().reorderSpaces(text1) << endl;

    string text2 = " practice   makes   perfect";
    cout << Solution().reorderSpaces(text2) << endl;

    string text3 = "hello   world";
    cout << Solution().reorderSpaces(text3) << endl;

    string text4 = "  walks  udp package   into  bar a";
    cout << Solution().reorderSpaces(text4) << endl;

    string text5 = "a";
    cout << Solution().reorderSpaces(text5) << endl;

    return 0;
}
