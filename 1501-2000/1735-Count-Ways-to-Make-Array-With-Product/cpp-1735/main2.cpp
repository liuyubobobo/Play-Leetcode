/// Source : https://leetcode.com/problems/count-ways-to-make-array-with-product/
/// Author : liuyubobobo
/// Time   : 2021-01-28

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Shieve Prime Numbers and using dp to calculate combinations
/// Time Complexity: O(q + maxk + maxn + maxk * log(maxk) + q * logk)
/// Space Complexity: O(maxk + maxn)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {

        int maxk = 0, maxn = 0;
        for(int i = 0; i < queries.size(); i ++){
            maxk = max(maxk, queries[i][1]);
            maxn = max(maxn, queries[i][0]);
        }

        vector<int> first = shieve(maxk);

        vector<vector<int>> C(maxk + maxn, vector<int>(32, 1));
        for(int i = 2; i < C.size(); i ++)
            for(int j = 1; j < min(i, 32); j ++)
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;

        vector<int> ret(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            int n = queries[i][0], k = queries[i][1];

            unordered_map<int, int> d;
            while(k != 1) d[first[k]] ++, k /= first[k];

            long long res = 1ll;
            for(const pair<int, int>& p: d)
                res = res * (long long)C[p.second + n - 1][p.second] % MOD;
            ret[i] = res;
        }
        return ret;
    }

private:
    vector<int> shieve(int n){

        vector<int> first(n + 1, 0);
        for(int i = 2; i <= n; i ++)
            if(first[i] == 0){
                for(int k = i; k <= n; k += i)
                    first[k] = i;
            }
        return first;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> queries1 = {{2, 6}, {5, 1}, {73, 660}};
    print_vec(Solution().waysToFillArray(queries1));
    // 4 1 50734910

    vector<vector<int>> queries2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    print_vec(Solution().waysToFillArray(queries2));
    // 1 2 3 10 5

    return 0;
}
