/// Source : https://leetcode.com/problems/similar-string-groups/solution/
/// Author : liuyubobobo
/// Time   : 2021-01-30

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// UF
/// Time Complexity: O(n^2 * |str|)
/// Space Complexity: O(n^2)
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

    bool isConnected(int p, int q){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){

        int pRoot = find(p), qRoot = find(q);

        if(pRoot == qRoot) return;

        parent[pRoot] = qRoot;
        sz --;
    }

    int size(){
        return sz;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();

        UF uf(n);
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(similar(strs[i], strs[j]))
                    uf.unionElements(i, j);

        return uf.size();
    }

private:
    bool similar(string& a, string& b){

        if(a == b) return true;

        int i = -1, j = -1;
        for(int k = 0; k < a.size(); k ++)
            if(a[k] != b[k]){
                if(i == -1) i = k;
                else if(j == -1) j = k;
                else return false;
            }

        return a[i] == b[j] && a[j] == b[i];
    }
};


int main() {

    return 0;
}
