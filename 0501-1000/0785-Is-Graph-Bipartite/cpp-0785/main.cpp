/// Source : https://leetcode.com/problems/is-graph-bipartite/description/
/// Author : liuyubobobo
/// Time   : 2018-03-09

#include <iostream>
#include <vector>

using namespace std;


/// Recursive Check
/// Time Complexity: O(v + e)
/// Space Complexity: O(v)
class Solution {

private:
    vector<int> checked;

public:
    bool isBipartite(vector<vector<int>>& graph) {

        checked = vector<int>(graph.size(), -1);
        for(int i = 0 ; i < graph.size() ; i ++)
            if(checked[i] == -1)
                if(!check(graph, i, 0))
                    return false;
        return true;
    }

private:
    bool check(const vector<vector<int>>& graph, int index, int group){

        if(checked[index] != -1)
            return checked[index] == group;

        checked[index] = group;
        for(int next: graph[index])
            if(!check(graph, next, 1 - group))
                return false;
        return true;
    }
};

void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}


int main() {

    vector<vector<int>> graph1 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    printBool(Solution().isBipartite(graph1));

    vector<vector<int>> graph2 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    printBool(Solution().isBipartite(graph2));

    return 0;
}