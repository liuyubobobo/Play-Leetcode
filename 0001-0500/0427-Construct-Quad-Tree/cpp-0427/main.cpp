/// Source : https://leetcode.com/problems/construct-quad-tree/
/// Author : liuyubobobo
/// Time   : 2022-04-28

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(N^2)
/// Space Complexity: O(N^2)

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {

        int N = grid.size();
        vector<vector<int>> presum(N + 1, vector<int>(N + 1, 0));
        for(int i = 0; i < N; i ++)
            for(int j = 0; j < N; j ++)
                presum[i + 1][j + 1] = presum[i + 1][j] + presum[i][j + 1] - presum[i][j] + grid[i][j];

        return construct(grid, presum, 0, 0, N - 1, N - 1);
    }

private:
    Node* construct(const vector<vector<int>>& grid, const vector<vector<int>>& presum,
                    int x1, int y1, int x2, int y2){

        int value = presum[x2 + 1][y2 + 1] - presum[x1][y2 + 1] - presum[x2 + 1][y1] + presum[x1][y1];
        int area = (y2 - y1 + 1) * (x2 - x1 + 1);
        if(value == area || value == 0)
            return new Node(value, true);

        int N = (y2 - y1 + 1);
        Node* node0 = construct(grid, presum, x1, y1, x1 + N / 2 - 1, y1 + N / 2 - 1);
        Node* node1 = construct(grid, presum, x1, y1 + N / 2, x1 + N / 2 - 1, y1 + N - 1);
        Node* node2 = construct(grid, presum, x1 + N / 2, y1, x1 + N - 1, y1 + N / 2 - 1);
        Node* node3 = construct(grid, presum, x1 + N / 2, y1 + N / 2, x1 + N - 1, y1 + N - 1);
        return new Node(value, false, node0, node1, node2, node3);
    }
};


int main() {

    vector<vector<int>> g1 = {{0, 1}, {1, 0}};
    Solution().construct(g1);

    return 0;
}
