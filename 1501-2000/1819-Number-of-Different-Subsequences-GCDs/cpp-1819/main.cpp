#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {

        vector<string> v;
        for(int start = 0, i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == ' '){
                v.push_back(s.substr(start, i - start));
                start = i + 1;
                i = start;
            }

        string res = "";
        for(int i = 0; i < k; i ++)
            res += v[i] + " ";
        res.pop_back();
        return res;
    }
};

int main() {

    return 0;
}
