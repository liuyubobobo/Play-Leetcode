/// Source : https://leetcode.com/problems/open-the-lock/description/
/// Author : liuyubobobo
/// Time   : 2017-12-23

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

/// BFS
/// Time Complexity: O(charset^N)
/// Space Complexity: O(charset^N)
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        set<string> dead;
        for(string s: deadends)
            dead.insert(s);

        if(dead.find(target) != dead.end() || dead.find("0000") != dead.end())
            return -1;

        set<string> visited;
        queue<pair<string, int>> q;
        q.push(make_pair("0000", 0));
        visited.insert("0000");
        while(!q.empty()){
            string cur = q.front().first;
            int step = q.front().second;
            q.pop();

            vector<string> next = getNext(cur, dead);
            for(string next_s: next)
                if(visited.find(next_s) == visited.end()){
                    if(next_s == target)
                        return step + 1;

                    visited.insert(next_s);
                    q.push(make_pair(next_s, step + 1));
                }
        }
        return -1;
    }

private:
    vector<string> getNext(const string& s, const set<string>& dead){
        vector<string> res;
        assert(s.size() == 4);
        for(int i = 0 ; i < 4 ; i ++){
            int num = s[i] - '0';

            int d = num + 1;
            if(d > 9) d = 0;
            string t = s;
            t[i] = ('0' + d);
            if(dead.find(t) == dead.end())
                res.push_back(t);

            d = num - 1;
            if(d < 0) d = 9;
            t = s;
            t[i] = ('0' + d);
            if(dead.find(t) == dead.end())
                res.push_back(t);
        }
        return res;
    }
};


int main() {

    vector<string> dead1 = {"0201","0101","0102","1212","2002"};
    string target1 = "0202";
    cout << Solution().openLock(dead1, target1) << endl;

    vector<string> dead2 = {"8888"};
    string target2 = "0009";
    cout << Solution().openLock(dead2, target2) << endl;

    vector<string> dead3 = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target3 = "8888";
    cout << Solution().openLock(dead3, target3) << endl;

    vector<string> dead4 = {"1002","1220","0122","0112","0121"};
    string target4 = "1200";
    cout << Solution().openLock(dead4, target4) << endl;

    return 0;
}