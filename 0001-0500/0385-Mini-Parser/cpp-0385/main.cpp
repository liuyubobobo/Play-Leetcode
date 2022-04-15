/// Source : https://leetcode.com/problems/mini-parser/
/// Author : liuyubobobo
/// Time   : 2022-04-14

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Recursive
/// Time Complexity: O(n)
/// Space Complexity: O(n)

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {

private:
    bool is_integer;
    int x;
    vector<NestedInteger> v;

public:
    // Constructor initializes an empty nested list.
    NestedInteger(){}

    // Constructor initializes a single integer.
    NestedInteger(int value) : is_integer(true), x(value){};

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger(){
        return is_integer;
    };

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger(){
        assert(is_integer);
        return x;
    };

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value){
        is_integer = true;
        x = value;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni){
        is_integer = false;
        v.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> getList() const{
        return v;
    }
};

class Solution {
public:
    NestedInteger deserialize(string s) {

        int n = s.size();
        vector<int> right(n, -1), stack;
        for(int i = 0; i < n; i ++){
            if(s[i] == '[') stack.push_back(i);
            else if(s[i] == ']'){
                assert(!stack.empty());
                int l = stack.back(); stack.pop_back();
                right[l] = i;
            }
        }
        return dfs(s, 0, n - 1, right);
    }

private:
    NestedInteger dfs(const string& s, int l, int r, const vector<int>& right){

        if(l + 1 == r && s[l] == '['){
            NestedInteger res;
            return res;
        }

        if(isdigit(s[l]) || s[l] == '-'){
            NestedInteger res;
            int x = atol(s.substr(l, r - l + 1).c_str());
            res.setInteger(x);
            return res;
        }

        assert(s[l] == '[' && s[r] == ']');
        NestedInteger res;
        for(int start = l + 1, i = l + 1; i <= r;){
            if(i == r || s[i] == ','){
                res.add(dfs(s, start, i - 1, right));
                start = i + 1;
                i = start;
            }
            else if(s[i] == '['){
                assert(right[i] <= r && s[right[i]] == ']');
                res.add(dfs(s, i, right[i], right));
                start = right[i] + 2;
                i = start;
            }
            else i ++;
        }
        return res;
    }
};


int main() {

    Solution().deserialize("[123,[456,[789]]]");

    Solution().deserialize("-3");

    return 0;
}
