/// Source : https://leetcode.com/problems/spiral-matrix-iv/
/// Author : liuyubobobo
/// Time   : 2022-07-02

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Simulation
/// Time Complexity: O(m * n)
/// Space Complexity: O(1)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int R, C;

public:
    vector<vector<int>> spiralMatrix(int R, int C, ListNode* node) {

        this->R = R, this->C = C;
        vector<vector<int>> res(R, vector<int>(C, -1));

        int cx = 0, cy = -1, d = 0;
        while(node){
            int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
            if(!in_area(nx, ny) || res[nx][ny] != -1){
                d = (d + 1) % 4;
                nx = cx + dirs[d][0], ny = cy + dirs[d][1];
//                assert(in_area(nx, ny));
            }

            res[nx][ny] = node->val;
            node = node->next;
            cx = nx, cy = ny;
        }
        return res;
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
