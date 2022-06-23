/// Source : https://leetcode.cn/contest/sf-tech/problems/cINqyA/
/// Author : liuyubobobo
/// Time   : 2022-06-23

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Meet in the middle
/// Time complexity: O(n * 2^(n / 2))
/// Space Complexity: O(2^(n/2))
class Solution {
public:
    int minRemainingSpace(vector<int>& V, int C) {

        int n = V.size();
        if(n == 1) return max(C - V[0], 0);

        int left_n = n / 2, right_n = n - left_n;
        vector<int> left(1 << left_n, 0), right(1 << right_n, 0);
        for(int state = 1; state < (1 << left_n); state ++){
            int p = __builtin_ffs(state) - 1;
            left[state] = left[state - (1 << p)] + V[p];
        }
        for(int state = 1; state < (1 << right_n); state ++){
            int p = __builtin_ffs(state) - 1;
            right[state] = right[state - (1 << p)] + V[left_n + p];
        }

        set<int> left_set(left.begin(), left.end());
        set<int> right_set(right.begin(), right.end());

        int res = C;
        for(int e1: left){
            if(e1 > C) break;
            auto iter = right_set.upper_bound(C - e1);
            iter --;
            res = min(res, C - e1 - *iter);
        }

        return res;
    }
};


int main() {

    return 0;
}
