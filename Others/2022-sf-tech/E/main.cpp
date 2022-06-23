/// Source : https://leetcode.cn/contest/sf-tech/problems/BN8jAm/
/// Author : liuyubobobo
/// Time   : 2022-06-23

#include <iostream>
#include <vector>

using namespace std;


/// Using UF
/// Time Complexity: O(m^2)
/// Space Complexity: O(m)
class UF{

private:
    vector<int> parent;
    int sz;

public:
    UF(int n) : parent(n), sz(n){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    bool is_connected(int p, int q){
        return find(p) == find(q);
    }

    void union_elements(int p, int q){

        int p_root = find(p), q_root = find(q);

        if(p_root == q_root) return;

        parent[p_root] = q_root;
        sz --;
    }

    int get_sz(){
        return sz;
    }
};

class Solution {
public:
    bool isCompliance(vector<vector<int>>& distance, int n) {

        int m = distance.size();
        UF uf(m);

        for(int i = 0; i < m; i ++)
            for(int j = i + 1; j < m; j ++)
                if(distance[i][j] <= 2) uf.union_elements(i, j);
        return uf.get_sz() <= n;
    }
};


int main() {

    return 0;
}
