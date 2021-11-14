/// Source : https://leetcode.com/problems/process-restricted-friend-requests/
/// Author : liuyubobobo
/// Time   : 2021-11-13

#include <iostream>
#include <vector>

using namespace std;


/// UF - restore the old UF
/// Time Complexity: O(m * n)
/// Space Complexity: O(n)
class UF{

public:
    vector<int> parent;

    UF(int n) : parent(n){
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
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {

        UF uf(n);

        int q = requests.size();
        vector<bool> res(q);
        for(int i = 0; i < q; i ++){

            vector<int> old_uf = uf.parent;

            int a = requests[i][0], b = requests[i][1];
            uf.union_elements(a, b);

            bool ok = true;
            for(const vector<int>& r: restrictions)
                if(uf.is_connected(r[0], r[1])){ok = false; break;}

            res[i] = ok;
            if(!ok) uf.parent = old_uf;
        }
        return res;
    }
};


int main() {

    return 0;
}
