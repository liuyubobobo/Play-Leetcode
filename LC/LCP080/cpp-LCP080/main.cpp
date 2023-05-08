/// Source : https://leetcode.cn/problems/qoQAMX/
/// Author : liuyubobobo
/// Time   : 2023-05-07

#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <map>
#include <algorithm>

using namespace std;


/// Tree Encoding
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    string evolutionaryRecord(vector<int>& parents) {

        int n = parents.size();
        vector<list<int>> tree(n);
        int root = -1;
        for(int i = 0; i < n; i ++){
            if(parents[i] != -1) tree[parents[i]].push_back(i);
            else root = i;
        }
        assert(root != -1);

        map<vector<int>, int> table;
        vector<string> tree2str(n);
        string res = tree2str[encode(tree, root, table, tree2str)];
        while(res.back() == '1') res.pop_back();
        return res;
    }

private:
    int encode(const vector<list<int>>& tree, int u, map<vector<int>, int>& table, vector<string>& tree2str){

        vector<int> subtrees;
        for(int v: tree[u]){
            subtrees.push_back(encode(tree, v, table, tree2str));
        }
        sort(subtrees.begin(), subtrees.end());

        if(!table.count(subtrees)){
            table[subtrees] = table.size();

            vector<string> v;
            for(int subtree: subtrees){
                v.push_back("0" + tree2str[subtree] + "1");
            }
            sort(v.begin(), v.end());
            string res = "";
            for(const string& s: v) res += s;
            tree2str[table[subtrees]] = res;
        }
        return table[subtrees];
    }
};


int main() {

    vector<int> parents1 = {-1, 0, 0, 2};
    cout << Solution().evolutionaryRecord(parents1) << endl;
    // 00110

    return 0;
}
