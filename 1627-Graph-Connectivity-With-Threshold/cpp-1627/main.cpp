/// Source : https://leetcode.com/problems/graph-connectivity-with-threshold/
/// Author : liuyubobobo
/// Time   : 2020-11-17

#include <iostream>
#include <vector>

using namespace std;


/// UF
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class UF{

private:
    vector<int> parent;

public:
    UF(int n){
        for(int i = 0 ; i < n ; i ++)
            parent.push_back(i);
    }

    int find(int p){
        if( p != parent[p] )
            parent[p] = find( parent[p] );
        return parent[p];
    }

    bool isConnected(int p , int q){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){

        int pRoot = find(p);
        int qRoot = find(q);

        if( pRoot == qRoot )
            return;

        parent[pRoot] = qRoot;
    }
};

class Solution {

public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {

        UF uf(n + 1);
        for(int t = threshold + 1; t <= n; t ++)
            for(int k = 1; k * t <= n; k ++)
                uf.unionElements(t, k * t);

        vector<bool> res;
        for(const vector<int>& q: queries)
            res.push_back(uf.isConnected(q[0], q[1]));
        return res;
    }
};


void print_vec(const vector<bool>& v){
    for(bool e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> queries1 = {{1, 4}, {2, 5}, {3, 6}};
    print_vec(Solution().areConnected(6, 2, queries1));
    // 0 0 1

    vector<vector<int>> queries2 = {{4, 5}, {3, 4}, {3, 2}, {2, 6}, {1, 3}};
    print_vec(Solution().areConnected(6, 0, queries2));
    // 1 1 1 1 1

    vector<vector<int>> queries3 = {{4, 5}, {4, 5}, {3, 2}, {2, 3}, {3, 4}};
    print_vec(Solution().areConnected(5, 1, queries3));
    // 0 0 0 0 0

    return 0;
}
