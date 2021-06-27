/// Source : https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/
/// Author : liuyubobobo
/// Time   : 2021-06-26

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// See here for details: https://codeforces.com/blog/entry/75627
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;
    vector<long long> fac;

public:
    int waysToBuildRooms(vector<int>& prevRoom) {

        int n = prevRoom.size();

        fac.clear();
        fac.push_back(1ll);
        for(int i = 1; i <= n; i ++)
            fac.push_back(fac[i - 1] * i % MOD);

        vector<vector<int>> tree(n);
        for(int i = 1; i < n; i ++)
            tree[prevRoom[i]].push_back(i);

        vector<int> sz(n, 0);
        get_sz(tree, 0, -1, sz);

        long long res = fac[n];
        for(int i = 0; i < n; i ++)
            res = res * mypow(sz[i], MOD - 2) % MOD;
        return res;
    }

private:
    void get_sz(const vector<vector<int>>& tree, int u, int p, vector<int>& sz){

        sz[u] = 1;
        for(int v: tree[u])
            if(v != p){
                get_sz(tree, v, u, sz);
                sz[u] += sz[v];
            }
    }

    long long mypow(long long a, int k){

        if(k == 0) return 1ll;
        long long res = mypow(a, k / 2);
        res = res * res % MOD;
        if(k % 2) res = res * a % MOD;
        return res;
    }
};


int main() {

    vector<int> prevRoom1 = {-1, 0, 1};
    cout << Solution().waysToBuildRooms(prevRoom1) << endl;
    // 1

    vector<int> prevRoom2 = {-1, 0, 0, 1, 2};
    cout << Solution().waysToBuildRooms(prevRoom2) << endl;
    // 6


    return 0;
}
