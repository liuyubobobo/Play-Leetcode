/// Source : https://leetcode.com/problems/reconstruct-itinerary/
/// Author : liuyubobobo
/// Time   : 2022-01-27

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;


/// Euler Path
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        map<string, vector<string>> g;
        for(const vector<string>& e: tickets) g[e[0]].push_back(e[1]);
        for(const pair<string, vector<string>>& p: g)
            sort(g[p.first].begin(), g[p.first].end(), greater<string>());

        vector<string> res;

        stack<string> stack;
        stack.push("JFK");
        while(!stack.empty()){
            if(g[stack.top()].size()){
                string u = stack.top(), v = g[u].back();
                stack.push(v);
                g[u].pop_back();
            }
            else{
                res.push_back(stack.top());
                stack.pop();
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    return 0;
}
