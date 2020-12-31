/// Source : https://leetcode.com/problems/longest-happy-string/
/// Author : liuyubobobo
/// Time   : 2020-04-08

#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using namespace std;


/// Generate a template and fill the redundant most characters
/// Time Complexity: O(a + b + c)
/// Space Complexity: O(1)
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        vector<pair<int, char>> v;
        v.push_back(make_pair(a, 'a'));
        v.push_back(make_pair(b, 'b'));
        v.push_back(make_pair(c, 'c'));

        string t = generate_template(v);
//        cout << "template = "<< t << endl;

        map<char, int> left;
        for(const pair<int, char>& p: v)
            left[p.second] = p.first;

        string res = "";
        for(char ch: t){
            res += ch;
            if(left[ch]) res += ch, left[ch] --;
        }
        return res;
    }

private:
    string generate_template(vector<pair<int, char>>& v){

        sort(v.begin(), v.end(), greater<pair<int, char>>());

        string tres = "";

        /// if a >= b >= c, then, b = 0
        while(v[0].first){
            tres += v[0].second;
            v[0].first --;
            if(v[1].first) tres += v[1].second, v[1].first --;
            else if(v[2].first) tres += v[2].second, v[2].first --;
            else break;
        }
        assert(v[1].first == 0);

        // deal with c
        string res = "";
        int i = 0;
        for(i = 0; i < tres.size() && v[2].first; i ++)
            if(tres[i] != v[2].second) res += v[2].second, res += tres[i], v[2].first --;
            else break;
        return res + tres.substr(i);
    }
};


int main() {

    cout << Solution().longestDiverseString(1, 1, 7) << endl;
    cout << "ccaccbcc" << endl;
    // ccaccbcc
    cout << endl;

    cout << Solution().longestDiverseString(2, 2, 1) << endl;
    cout << "aabbc" << endl;
    // aabbc
    cout << endl;

    cout << Solution().longestDiverseString(7, 1, 0) << endl;
    cout << "aabaa" << endl;
    // aabaa
    cout << endl;

    cout << Solution().longestDiverseString(0, 8, 11) << endl;
    cout << "ccbccbbccbbccbbccbc" << endl;
    // ccbccbbccbbccbbccbc
    cout << endl;

    cout << Solution().longestDiverseString(4, 4, 3) << endl;
    cout << "aabbccaabbc" << endl;
    // aabbccaabbc
    cout << endl;

    cout << Solution().longestDiverseString(1, 1, 7) << endl;
    cout << "ccaccbcc" << endl;
    // ccaccbcc
    cout << endl;

    return 0;
}