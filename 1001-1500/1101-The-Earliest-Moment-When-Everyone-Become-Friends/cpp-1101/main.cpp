/// Source : https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/
/// Author : liuyubobobo
/// Time   : 2019-06-30

#include <iostream>
#include <vector>

using namespace std;


/// Sorting + Union Find
/// Time Complexity: O(nlogn + n * a(n))
/// Space Complexity: O(n)
class UF{

private:
    vector<int> parent;
    int size;

public:
    UF(int n){
        for(int i = 0 ; i < n ; i ++)
            parent.push_back(i);
        size = n;
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
        size --;
    }

    int sz(){
        return size;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& log1, const vector<int>& log2){
           return log1[0] < log2[0];
        });

        UF uf(N);
        for(const vector<int>& log: logs){
            uf.unionElements(log[1], log[2]);
            if(uf.sz() == 1) return log[0];
        }
        return -1;
    }
};


int main() {

    return 0;
}