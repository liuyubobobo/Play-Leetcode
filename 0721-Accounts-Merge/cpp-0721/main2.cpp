/// Source : https://leetcode.com/problems/accounts-merge/description/
/// Author : liuyubobobo
/// Time   : 2017-11-25

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

/// Using Union-Find
/// Time Complexity: O(len(emails))
/// Space Complexity: O(len(emails))

class UnionFind{

private:
    // rank[i]表示以i为根的集合所表示的树的层数
    // 在后续的代码中, 我们并不会维护rank的语意, 也就是rank的值在路径压缩的过程中, 有可能不在是树的层数值
    // 这也是我们的rank不叫height或者depth的原因, 他只是作为比较的一个标准
    // 关于这个问题，可以参考问答区：http://coding.imooc.com/learn/questiondetail/7287.html
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        map<string, string> emailToName;
        for(const vector<string>& account: accounts)
            for(int i = 1 ; i < account.size() ; i ++)
                emailToName[account[i]] = account[0];

        unordered_map<string, int> emailIndex;
        int index = 0;
        for(const pair<string, string>& p: emailToName)
            emailIndex.insert(make_pair(p.first, index ++));

        vector<string> intToEmail(emailIndex.size(), "");
        for(const pair<string, int>& p: emailIndex)
            intToEmail[p.second] = p.first;

        UnionFind uf(emailIndex.size());
        for(const vector<string>& account: accounts){
            int index1 = emailIndex[account[1]];
            for(int i = 2 ; i < account.size() ; i ++){
                int index2 = emailIndex[account[i]];
                uf.unionElements(index1, index2);
            }
        }

        vector<vector<string>> res;
        vector<bool> flag(emailIndex.size(), false);
        for(int i = 0 ; i < emailIndex.size() ; i ++)
            if(!flag[i]){
                vector<string> emails;
                emails.push_back(intToEmail[i]);
                flag[i] = true;
                for(int j = i + 1 ; j < emailIndex.size() ; j ++)
                    if(!flag[j] && uf.isConnected(i, j)){
                        flag[j] = true;
                        emails.push_back(intToEmail[j]);
                    }

                sort(emails.begin(), emails.end());
                string name = emailToName[emails[0]];

                vector<string> tres;
                tres.push_back(name);
                for(const string& email: emails)
                    tres.push_back(email);

                res.push_back(tres);
            }


        return res;
    }
};


void printRes(const vector<vector<string>> res){
    for(const vector<string>& row: res){
        for(const string& e: row)
            cout << e << " ";
        cout << endl;
    }
}

int main() {

    vector<vector<string>> accounts = {
            {"John", "johnsmith@mail.com", "john00@mail.com"},
            {"John", "johnnybravo@mail.com"},
            {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
            {"Mary", "mary@mail.com"}
    };
    printRes(Solution().accountsMerge(accounts));

    return 0;
}