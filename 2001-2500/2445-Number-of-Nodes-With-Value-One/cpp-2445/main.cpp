/// Source : https://leetcode.com/problems/number-of-nodes-with-value-one/
/// Author : liuyubobobo
/// Time   : 2022-10-20

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {

        vector<int> qtable(n + 1, 0);
        for(int q: queries) qtable[q] ^= 1;

        int res = 0;
        for(int i = 1; i <= n; i ++){
            int x = i, t = 0;
            while(x){
                t ^= qtable[x];
                x >>= 1;
            }
            res += t;
        }
        return res;
    }
};


int main() {

    return 0;
}
