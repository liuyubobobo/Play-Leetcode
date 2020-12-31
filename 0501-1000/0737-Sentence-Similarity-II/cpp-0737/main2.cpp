/// Source : https://leetcode.com/problems/sentence-similarity-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-26

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Using Union-Find
/// Time Complexity: O(len(words))
/// Space Complexity: O(len(words))
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
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2,
                                vector<pair<string, string>> pairs) {

        if(words1.size() != words2.size())
            return false;

        if(words1.size() == 0)
            return true;

        unordered_map<string, int> wordIndex = createWordIndex(pairs);
        UnionFind uf = createUF(wordIndex, pairs);

        for(int i = 0 ; i < words1.size() ; i ++){
            if(words1[i] == words2[i])
                continue;

            if(wordIndex.find(words1[i]) == wordIndex.end() ||
               wordIndex.find(words2[i]) == wordIndex.end())
                return false;

            if(!uf.isConnected(wordIndex[words1[i]], wordIndex[words2[i]]))
                return false;
        }

        return true;
    }

private:

    UnionFind createUF(
            const unordered_map<string, int>& wordIndex,
            const vector<pair<string, string>>& pairs){

        UnionFind uf(wordIndex.size());
        for(pair<string, string> p: pairs){
            int i1 = wordIndex.at(p.first);
            int i2 = wordIndex.at(p.second);
            uf.unionElements(i1, i2);
        }

        return uf;
    }

    unordered_map<string, int> createWordIndex(const vector<pair<string, string>>& pairs){

        unordered_map<string, int> wordIndex;
        int index = 0;
        for(pair<string, string> p: pairs){
            if(wordIndex.find(p.first) == wordIndex.end())
                wordIndex.insert(make_pair(p.first, index ++));
            if(wordIndex.find(p.second) == wordIndex.end())
                wordIndex.insert(make_pair(p.second, index ++));
        }
        return wordIndex;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<string> words1_a = {"great", "acting", "skills"};
    vector<string> words2_a = {"fine", "drama", "talent"};

    vector<pair<string, string>> pairs_a;
    pairs_a.push_back(make_pair("great", "good"));
    pairs_a.push_back(make_pair("fine", "good"));
    pairs_a.push_back(make_pair("acting", "drama"));
    pairs_a.push_back(make_pair("skills", "talent"));

    printBool(Solution().areSentencesSimilarTwo(words1_a, words2_a, pairs_a));
    // True

    // ---

    vector<string> words1_b = {"an", "extraordinary", "meal"};
    vector<string> words2_b = {"one", "delicious", "dinner"};

    vector<pair<string, string>> pairs_b;
    pairs_b.push_back(make_pair("great", "good"));
    pairs_b.push_back(make_pair("extraordinary", "good"));
    pairs_b.push_back(make_pair("well", "good"));
    pairs_b.push_back(make_pair("wonderful", "good"));
    pairs_b.push_back(make_pair("excellent", "good"));
    pairs_b.push_back(make_pair("fine", "good"));
    pairs_b.push_back(make_pair("nice", "good"));
    pairs_b.push_back(make_pair("any", "one"));
    pairs_b.push_back(make_pair("some", "one"));
    pairs_b.push_back(make_pair("unique", "one"));
    pairs_b.push_back(make_pair("the", "one"));
    pairs_b.push_back(make_pair("an", "one"));
    pairs_b.push_back(make_pair("single", "one"));
    pairs_b.push_back(make_pair("a", "one"));
    pairs_b.push_back(make_pair("truck", "car"));
    pairs_b.push_back(make_pair("wagon", "car"));
    pairs_b.push_back(make_pair("automobile", "car"));
    pairs_b.push_back(make_pair("auto", "car"));
    pairs_b.push_back(make_pair("vehicle", "car"));
    pairs_b.push_back(make_pair("entertain", "have"));
    pairs_b.push_back(make_pair("drink", "have"));
    pairs_b.push_back(make_pair("eat", "have"));
    pairs_b.push_back(make_pair("take", "have"));
    pairs_b.push_back(make_pair("fruits", "meal"));
    pairs_b.push_back(make_pair("brunch", "meal"));
    pairs_b.push_back(make_pair("breakfast", "meal"));
    pairs_b.push_back(make_pair("food", "meal"));
    pairs_b.push_back(make_pair("dinner", "meal"));
    pairs_b.push_back(make_pair("super", "meal"));
    pairs_b.push_back(make_pair("lunch", "meal"));
    pairs_b.push_back(make_pair("possess", "own"));
    pairs_b.push_back(make_pair("keep", "own"));
    pairs_b.push_back(make_pair("have", "own"));
    pairs_b.push_back(make_pair("extremely", "very"));
    pairs_b.push_back(make_pair("actually", "very"));
    pairs_b.push_back(make_pair("really", "very"));
    pairs_b.push_back(make_pair("super", "very"));

    printBool(Solution().areSentencesSimilarTwo(words1_b, words2_b, pairs_b));
    //False

    return 0;
}