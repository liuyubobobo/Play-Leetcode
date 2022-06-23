/// Source : https://leetcode.cn/contest/sf-tech/problems/EUpcmh/
/// Author : liuyubobobo
/// Time   : 2022-06-23

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cassert>

using namespace std;


/// DFS Cycle Finding
/// Time Complexity: O(|s| + n)
/// Space Compelxity: O(n)
class Solution {
public:
    bool hasCycle(string graph) {

        vector<string> edges_str = get_edges_str(graph);

        map<int, set<int>> g;
        for(const string& edge_str: edges_str){
            int u, v;
            get_uv_from_edge_str(edge_str, u, v);
            g[u].insert(v);
        }

        set<int> visited;
        bool has_cycle = false;
        for(const pair<int, set<int>>& p: g){
            int u = p.first;
            if(!visited.count(u)){
                set<int> stack;
                has_cycle = dfs(g, u, stack, visited);
                if(has_cycle) break;
            }
        }
        return has_cycle;
    }

private:
    bool dfs(const map<int, set<int>>& g, int u, set<int>& stack, set<int>& visited){

        stack.insert(u);
        if(g.count(u)){
            for(int v: g.at(u)){
                if(stack.count(v)) return true;
                if(!visited.count(v) && dfs(g, v, stack, visited)) return true;
            }
        }
        stack.erase(u);
        return false;
    }

    void get_uv_from_edge_str(const string& e, int& u, int& v){

        int arrow_pos = e.find("->");
        assert(arrow_pos != string::npos);

        u = atoi(e.substr(0, arrow_pos).c_str());
        v = atoi(e.substr(arrow_pos + 2).c_str());
    }

    vector<string> get_edges_str(const string& g){

        vector<string> res;
        for(int start = 0, i = 1; i <= g.size(); i ++)
            if(i == g.size() || g[i] == ','){
                res.push_back(g.substr(start, i - start));
                start = i + 1;
                i = start + 1;
            }
        return res;
    }
};


int main() {

    cout << Solution().hasCycle("1->2,2->3,3->1") << '\n';
    // 1

    cout << Solution().hasCycle("1->4,2->5,3->6,3->7,4->8,5->8,5->9,6->9,6->11,7->11,8->12,9->12,9->13,10->13,10->14,11->10,11->14") << '\n';
    // 0

    cout << Solution().hasCycle("1->4,2->5,3->6,3->7,4->8,5->8,5->9,6->9,6->11,7->11,8->12,9->12,9->13,10->6,10->13,10->14,11->10,11->14") << '\n';
    // 1

    return 0;
}
