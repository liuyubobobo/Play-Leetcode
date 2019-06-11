/// Source : https://leetcode.com/problems/flatten-nested-list-iterator/
/// Author : liuyubobobo
/// Time   : 2019-06-10

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {

public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const{return true;}

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const{return -1;}

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const{return {};}
};

class NestedIterator {

private:
    vector<int> data;
    int i;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {

        dfs(nestedList);
        i = 0;
    }

    int next() {

        return data[i ++];
    }

    bool hasNext() {
        return i < data.size();
    }

private:
    void dfs(const vector<NestedInteger>& nestedList){

        for(const NestedInteger& e: nestedList)
            if(e.isInteger())
                data.push_back(e.getInteger());
            else
                dfs(e.getList());
    }
};


int main() {

    return 0;
}