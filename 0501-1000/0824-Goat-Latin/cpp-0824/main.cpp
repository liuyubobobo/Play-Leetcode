/// Source : https://leetcode.com/problems/goat-latin/
/// Author : liuyubobobo
/// Time   : 2022-04-20

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Simulation
/// Time Compelxity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string toGoatLatin(string sentence) {

        vector<string> v;
        for(int start = 0, i = 1; i <= sentence.size(); i ++)
            if(i == sentence.size() || sentence[i] == ' '){
                v.push_back(sentence.substr(start, i - start));
                start = i + 1;
                i = start;
            }

        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        string res = "";
        for(int i = 0; i < v.size(); i ++){
            if(vowels.count(v[i][0]))
                res += v[i] + "ma";
            else
                res += v[i].substr(1) + v[i][0] + "ma";

            res += string(i + 1, 'a');
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};


int main() {

    return 0;
}
