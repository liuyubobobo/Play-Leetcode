/// Source : https://leetcode.com/problems/validate-binary-tree-nodes/
/// Author : liuyubobobo
/// Time   : 2020-02-22

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Constructing Graph
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<set<int>> g(n);
        vector<int> indegrees(n, 0);
        for(int i = 0; i < n; i ++)
            if(leftChild[i] != -1){
                if(i == leftChild[i]) return false;
                g[i].insert(leftChild[i]);
                indegrees[leftChild[i]] ++;
            }
        for(int i = 0; i < n; i ++)
            if(rightChild[i] != -1){
                if(i == rightChild[i] || g[i].count(rightChild[i]) || indegrees[rightChild[i]]) return false;
                g[i].insert(rightChild[i]);
                indegrees[rightChild[i]] ++;
            }

        int root = 0;
        for(int i = 0; i < n; i ++)
            root += (indegrees[i] == 0);
        return root == 1;
    }
};


int main() {

    return 0;
}
