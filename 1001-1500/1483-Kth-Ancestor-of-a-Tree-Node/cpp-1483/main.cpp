/// Source : https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Binary Lifting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(logk)
class TreeAncestor {

private:
    vector<vector<int>> dp;

public:
    TreeAncestor(int n, vector<int>& parent) : dp(n) {

        for(int i = 0; i < n; i ++)
            dp[i].push_back(parent[i]);

        for(int j = 1; ; j ++){
            bool allminus = true;
            for(int i = 0; i < n; i ++){
                int t = dp[i][j - 1] != -1 ? dp[dp[i][j - 1]][j - 1] : -1;
                dp[i].push_back(t);
                if(t != -1) allminus = false;
            }
            if(allminus) break;
        }
    }

    // 递归写法
//    int getKthAncestor(int node, int k) {
//
//        if(k == 0 || node == -1) return node;
//
//        int pos = ffs(k) - 1; // C++ 语言中 ffs(k) 求解出 k 的最右侧第一个 1 的位置（1-based）
//
//        return pos < dp[node].size() ? getKthAncestor(dp[node][pos], k - (1 << pos)) : -1;
//    }

    // 非递归写法
    int getKthAncestor(int node, int k) {

        int res = node, pos = 0;
        while(k && res != -1){
            if(pos >= dp[res].size()) return -1;
            if(k & 1) res = dp[res][pos];
            k >>= 1, pos ++;
        }
        return res;
    }
};


int main() {

    vector<int> tree1 = {-1, 0, 0, 1, 1, 2, 2};
    TreeAncestor o1(7, tree1);
    cout << o1.getKthAncestor(3, 1) << endl; // 1
    cout << o1.getKthAncestor(5, 2) << endl; // 0
    cout << o1.getKthAncestor(6, 3) << endl; // -1

    cout << endl;

    vector<int> tree2 = {-1, 0, 0, 1, 2, 0, 1, 3, 6, 1};
    TreeAncestor o2(10, tree2);
    cout << o2.getKthAncestor(8, 6) << endl; // -1
    cout << o2.getKthAncestor(9, 7) << endl; // -1
    cout << o2.getKthAncestor(1, 1) << endl; // 0
    cout << o2.getKthAncestor(2, 5) << endl; // -1
    cout << o2.getKthAncestor(4, 2) << endl; // 0
    cout << o2.getKthAncestor(7, 3) << endl; // 0
    cout << o2.getKthAncestor(3, 7) << endl; // -1
    cout << o2.getKthAncestor(9, 6) << endl; // -1
    cout << o2.getKthAncestor(3, 5) << endl; // -1
    cout << o2.getKthAncestor(8, 8) << endl; // -1

    return 0;
}
