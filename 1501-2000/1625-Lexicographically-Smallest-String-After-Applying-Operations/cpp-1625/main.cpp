/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2020-10-17

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;


/// BFS
/// Time Complexity: O(|s|)
/// Space Complexity: O(|s|)
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {

        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        string res = s;
        while(!q.empty()){

            string cur = q.front();
            q.pop();
            res = min(res, cur);

            string s1 = op1(cur, a);
            if(!visited.count(s1)){
                visited.insert(s1), q.push(s1);
            }

            string s2 = op2(cur, b);
            if(!visited.count(s2)){
                visited.insert(s2), q.push(s2);
            }
        }
        return res;
    }

private:
    string op1(string s, int a){

        for(int i = 1; i < s.size(); i += 2)
            s[i] = '0' + (s[i] - '0' + a) % 10;
        return s;
    }

    string op2(const string& s, int b){
        return s.substr(s.size() - b) + s.substr(0, s.size() - b);
    }
};


int main() {

    cout << Solution().findLexSmallestString("5525", 9, 2) << endl;
    // 2050

    cout << Solution().findLexSmallestString("74", 5, 1) << endl;
    // 24

    cout << Solution().findLexSmallestString("0011", 4, 2) << endl;
    // 0011

    cout << Solution().findLexSmallestString("43987654", 7, 3) << endl;
    // 00553311

    return 0;
}
