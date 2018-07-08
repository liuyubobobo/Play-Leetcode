#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {

        vector<int> freq(26, 0);
        for(char c: S)
            freq[c-'a'] ++;

        vector<pair<int, char>> vec;
        for(int i = 0 ; i < 26 ; i ++)
            if(freq[i])
                vec.push_back(make_pair(freq[i], 'a' + i));

        sort(vec.begin(), vec.end());
        //printPairVec(vec);

        vector<string> parts(vec.back().first, "");
        for(int i = 0 ; i < parts.size() ; i ++)
            parts[i] += vec.back().second;
        //printStringVec(parts);

        int index = 0;
        for(int i = vec.size() - 2 ; i >= 0 ; i --)
            for(int j = 0 ; j < vec[i].first; j ++){
                parts[index] += vec[i].second;
                index = (index + 1) % parts.size();
            }

        string res = "";
        for(int i = 0 ; i < parts.size(); i ++)
            if(res == "" || res[res.size()-1] != parts[i][0])
                res += parts[i];
            else
                return "";

        return res;
    }

private:
    void printPairVec(const vector<pair<int, char>>& vec){
        for(pair<int, char> e: vec)
            cout << e.first << " " << e.second << endl;
    }

    void printStringVec(const vector<string>& vec){
        for(string e: vec)
            cout << e << endl;
    }
};

int main() {

    cout << Solution().reorganizeString("aab") << endl;
    cout << Solution().reorganizeString("aaab") << endl;
    cout << Solution().reorganizeString("vlvov") << endl;

    return 0;
}