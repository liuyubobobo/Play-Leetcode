/// Source : https://leetcode.com/problems/range-product-queries-of-powers/
/// Author : liuyubobobo
/// Time   : 2022-10-15

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(logn + qlogn)
/// Space Complexity: O(logn)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        vector<int> powers;
        for(int p = 0; p <= 30; p ++)
            if((n >> p) & 1) powers.push_back(1 << p);

        int q = queries.size();
        vector<int> res(q);
        for(int i = 0; i < q; i ++){
            long long tres = 1;
            for(int j = queries[i][0]; j <= queries[i][1]; j ++)
                tres = tres * powers[j] % MOD;
            res[i] = tres;
        }
        return res;
    }
};


int main() {

    return 0;
}
