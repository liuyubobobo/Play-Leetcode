/// Source : https://leetcode.com/problems/evaluate-division/
/// Author : liuyubobobo
/// Time   : 2021-01-05

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// DFS
/// Time Complexity: O(q * n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, unordered_map<string, double>> g;
        for(int i = 0; i < values.size(); i ++)
            g[equations[i][0]][equations[i][1]] = values[i],
            g[equations[i][1]][equations[i][0]] = 1.0 / values[i];

        vector<double> res;
        for(const vector<string>& q: queries){
            unordered_set<string> visited;
            res.push_back(dfs(g, q[0], q[1], visited));
        }
        return res;
    }

private:
    double dfs(const unordered_map<string, unordered_map<string, double>>& g,
               const string& s, const string& t, unordered_set<string>& visited){

        if(!g.count(s)) return -1.0;
        if(s == t) return 1.0;

        visited.insert(s);
        for(const pair<string, double>& p: g.at(s))
            if(!visited.count(p.first)){
                double tres = dfs(g, p.first, t, visited);
                if(tres >= 0.0) return tres * p.second;
            }
        return -1.0;
    }
};


void print_vec(const vector<double>& res){
    for(double e: res) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<string>> equations1 = {{"a","b"},{"b","c"}};
    vector<double> values1 = {2.0, 3.0};
    vector<vector<string>> queries1 = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    print_vec(Solution().calcEquation(equations1, values1, queries1));
    // 6.00000,0.50000,-1.00000,1.00000,-1.00000

    vector<vector<string>> equations2 = {{"a","b"},{"b","c"},{"a","c"}};
    vector<double> values2 = {2.0, 3.0, 6.0};
    vector<vector<string>> queries2 = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    print_vec(Solution().calcEquation(equations2, values2, queries2));
    // 6.00000,0.50000,-1.00000,1.00000,-1.00000

    return 0;
}
