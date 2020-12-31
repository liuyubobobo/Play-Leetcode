/// Source : https://leetcode.com/problems/satisfiability-of-equality-equations/
/// Author : liuyubobobo
/// Time   : 2019-02-09

#include <iostream>
#include <vector>

using namespace std;


/// Using Union-Found
/// Time Complexity: O(n)
/// Space Complexity: O(26)
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
    bool equationsPossible(vector<string>& equations) {

        UF uf(26);
        for(const string& e: equations)
            if(e[1] == '=')
                uf.unionElements(e[0] - 'a', e[3] - 'a');

        for(const string& e: equations)
            if(e[1] == '!' && uf.isConnected(e[0] - 'a', e[3] - 'a'))
                return false;
        return true;
    }
};


int main() {

    return 0;
}