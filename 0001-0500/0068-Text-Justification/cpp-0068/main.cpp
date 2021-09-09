/// Source : https://leetcode.com/problems/text-justification/
/// Author : liuyubobobo
/// Time   : 2021-09-08

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> res;
        int index = 0;
        while(index < words.size()){

            vector<string> linev = {words[index ++]};
            int cur = linev[0].size();
            while(index < words.size() && cur + 1 + words[index].size() <= maxWidth){
                linev.push_back(words[index]),
                cur += (1 + words[index].size()),
                index ++;
            }

            string line = "";
            if(index < words.size()){
                int left = maxWidth - cur, space = linev.size() - 1;

                line = linev[0];
                for(int i = 1; i < linev.size(); i ++)
                    line += string(1 + left / space + (i- 1 < left % space), ' '),
                    line += linev[i];

                line += string(maxWidth - line.size(), ' ');
            }
            else{
                line = linev[0];
                for(int i = 1; i < linev.size(); i ++)
                    line += " " + linev[i];
                line += string(maxWidth - line.size(), ' ');
            }

            res.push_back(line);
        }
        return res;
    }
};


void print_text(const vector<string>& text){
    for(const string& line: text)
        cout << line << endl;
}

int main() {

    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    print_text(Solution().fullJustify(words1, 16));

    vector<string> words2 = {"What","must","be","acknowledgment","shall","be"};
    print_text(Solution().fullJustify(words2, 16));

    return 0;
}
