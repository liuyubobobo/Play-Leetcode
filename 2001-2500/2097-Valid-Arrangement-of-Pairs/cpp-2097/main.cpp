/// Source : https://leetcode.com/problems/valid-arrangement-of-pairs/
/// Author : liuyubobobo
/// Time   : 2021-12-05

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


/// Hierholzer’s Algorithm
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        unordered_map<int, vector<int>> g;
        unordered_map<int, int> in_degrees;
        for(const vector<int>& p: pairs){
            g[p[0]].push_back(p[1]);
            in_degrees[p[1]] ++;
        }

        int s = g.begin()->first;
        for(const pair<int, vector<int>>& p: g)
            if(p.second.size() - in_degrees[p.first] == 1){
                s = p.first;
                break;
            }

        vector<int> res;

        stack<int> stack;
        int curv = s;
        stack.push(curv);
        while(!stack.empty()){
            if(g[stack.top()].size()){
                int u = stack.top(), v = g[u].back();
                stack.push(v);
                g[u].pop_back();
            }
            else{
                res.push_back(stack.top());
                stack.pop();
            }
        }

        vector<vector<int>> ret;
        for(int i = res.size() - 1; i >= 1; i --)
            ret.push_back({res[i], res[i - 1]});
        return ret;
    }
};


void print_vec(const vector<vector<int>>& v){

    for(const vector<int>& p: v)
        cout << "(" << p[0] << "," << p[1] << ")";
    cout << endl;
}

int main() {

    vector<vector<int>> pairs1 = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    print_vec(Solution().validArrangement(pairs1));

    vector<vector<int>> pairs2 = {{1, 3}, {3, 2}, {2, 1}};
    print_vec(Solution().validArrangement(pairs2));

    vector<vector<int>> pairs3 = {{1, 2}, {1, 3}, {2, 1}};
    print_vec(Solution().validArrangement(pairs3));

    return 0;
}
