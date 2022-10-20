/// Source : https://leetcode.com/problems/k-th-symbol-in-grammar/
/// Author : liuyubobobo
/// Time   : 2022-10-20

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int kthGrammar(int n, int k) {
        return solve(0, n - 1, k - 1);
    }

private:
    int solve(int parent, int n, int k){
        if(n == 0) return parent;

        int mid = 1 << (n - 1);
        if(k < mid) return solve(parent == 0 ? 0 : 1, n - 1, k);
        return solve(parent == 0 ? 1 : 0, n - 1, k - mid);
    }
};


int main() {

    return 0;
}
