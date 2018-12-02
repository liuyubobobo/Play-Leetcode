/// Source : https://leetcode.com/problems/largest-component-size-by-common-factor/
/// Author : liuyubobobo
/// Time   : 2018-12-01

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;


/// Using Union Find
/// Time Complexity: O(n * sqrt(max_number))
/// Space Complexity: O(n * sqrt(max_number))

class UF{

private:
    vector<int> parent, sz;

public:
    UF(int n){
        for(int i = 0 ; i < n ; i ++){
            parent.push_back(i);
            sz.push_back(1);
        }
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
        sz[qRoot] += sz[pRoot];
    }

    int size(int p){
        return sz[find(p)];
    }
};

class Solution {

public:
    int largestComponentSize(vector<int>& A) {

        unordered_map<int, int> map; // a -> index
        for(int i = 0; i < A.size(); i ++)
            map[A[i]] = i;

        unordered_map<int, vector<int>> factors;
        UF uf(A.size());
        for(int a: A)
            for(int i = 1; i * i <= a; i ++)
                if(a % i == 0){
                    if(i != 1) {
                        if (!factors[i].empty())
                            uf.unionElements(map[a], map[factors[i][0]]);
                        factors[i].push_back(a);
                    }
                    if(i * i < a){
                        int j = a / i;
                        if(!factors[j].empty())
                            uf.unionElements(map[a], map[factors[j][0]]);
                        factors[j].push_back(a);
                    }
                }

        int res = 0;
        for(int a: A)
            res = max(res, uf.size(map[a]));
        return res;
    }
};


int main() {

    vector<int> A = {2,3,6,7,4,12,21,39};
    cout << Solution().largestComponentSize(A) << endl;
    // 8

    return 0;
}