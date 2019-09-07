/// Source : https://leetcode.com/problems/before-and-after-puzzle/
/// Author : liuyubobobo
/// Time   : 2019-09-07

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2 * (|s| + logn))
/// Space Complexity: O(n * |s|)
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {

        int n = phrases.size();

        set<string> res;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++){
                string m = merge(phrases[i], phrases[j]);
                if(m != "") res.insert(m);
                m = merge(phrases[j], phrases[i]);
                if(m != "") res.insert(m);
            }

        return vector<string>(res.begin(), res.end());
    }

private:
    string merge(const string& s1, const string& s2){

        vector<string> v1 = split(s1), v2 = split(s2);
        if(v1.back() != v2[0]) return "";
        for(int i = 1; i < v2.size(); i ++) v1.push_back(v2[i]);
        string res = v1[0];
        for(int i  = 1; i < v1.size(); i ++) res += " " + v1[i];
        return res;
    }

    vector<string> split(const string& s){

        vector<string> res;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == ' '){
                res.push_back(s.substr(start, i - start));
                start = i + 1;
                i = start;
            }
        return res;
    }
};


void print_vec(const vector<string>& vec){
    for(const string& e: vec) cout << e << endl; cout << endl;
}

int main() {

    vector<string> phrases1 = {"writing code","code rocks"};
    print_vec(Solution().beforeAndAfterPuzzles(phrases1));

    cout << endl;

    vector<string> phrases2 = {"mission statement",
                               "a quick bite to eat",
                               "a chip off the old block",
                               "chocolate bar",
                               "mission impossible",
                               "a man on a mission",
                               "block party",
                               "eat my words",
                               "bar of soap"};
    print_vec(Solution().beforeAndAfterPuzzles(phrases2));

    return 0;
}