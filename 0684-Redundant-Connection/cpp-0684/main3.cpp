/// Source : https://leetcode.com/problems/redundant-connection/description/
/// Author : liuyubobobo
/// Time   : 2017-12-01

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

/// Using Union-Find, add edges into the UF
/// The first edge make a circle is the result
/// Time Complexity: O(e)
/// Space Complexity: O(e)

class UnionFind{

private:
    int* rank;
    int* parent; // parent[i]表示第i个元素所指向的父节点
    int count;   // 数据个数

public:
    // 构造函数
    UnionFind(int count){
        parent = new int[count];
        rank = new int[count];
        this->count = count;
        for( int i = 0 ; i < count ; i ++ ){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    // 析构函数
    ~UnionFind(){
        delete[] parent;
        delete[] rank;
    }

    // 查找过程, 查找元素p所对应的集合编号
    // O(h)复杂度, h为树的高度
    int find(int p){
        assert( p >= 0 && p < count );

        // path compression 1
        while( p != parent[p] ){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    // 查看元素p和元素q是否所属一个集合
    // O(h)复杂度, h为树的高度
    bool isConnected( int p , int q ){
        return find(p) == find(q);
    }

    // 合并元素p和元素q所属的集合
    // O(h)复杂度, h为树的高度
    void unionElements(int p, int q){

        int pRoot = find(p);
        int qRoot = find(q);

        if( pRoot == qRoot )
            return;

        // 根据两个元素所在树的元素个数不同判断合并方向
        // 将元素个数少的集合合并到元素个数多的集合上
        if( rank[pRoot] < rank[qRoot] ){
            parent[pRoot] = qRoot;
        }
        else if( rank[qRoot] < rank[pRoot]){
            parent[qRoot] = pRoot;
        }
        else{ // rank[pRoot] == rank[qRoot]
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;   // 此时, 我维护rank的值
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        unordered_map<int, int> vIndex;
        int index = 0;
        for(const vector<int>& edge: edges){
            if(vIndex.find(edge[0]) == vIndex.end())
                vIndex[edge[0]] = index ++;
            if(vIndex.find(edge[1]) == vIndex.end())
                vIndex[edge[1]] = index ++;
        }

        UnionFind uf(vIndex.size());
        for(const vector<int>& edge: edges) {
            int v = vIndex[edge[0]];
            int w = vIndex[edge[1]];
            if (uf.isConnected(v, w))
                return edge;
            else uf.unionElements(v, w);
        }
        assert(false);
    }
};


void printVec(const vector<int>& v){
    for(int e: v)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> vec1 = {{1, 2}, {1, 3}, {2, 3}};
    printVec(Solution().findRedundantConnection(vec1));

    vector<vector<int>> vec2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    printVec(Solution().findRedundantConnection(vec2));

    return 0;
}