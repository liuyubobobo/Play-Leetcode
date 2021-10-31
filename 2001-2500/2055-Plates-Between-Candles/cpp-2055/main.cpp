/// Source : https://leetcode.com/problems/plates-between-candles/
/// Author : liuyubobobo
/// Time   : 2021-10-30

#include <iostream>
#include <vector>

using namespace std;


/// Using BIT
/// Time Complexity: O(nlogn + qlogn)
/// Space Complexity: O(n)
template<typename T>
class BIT{

private:
    int n;
    vector<T> data;
    vector<T> tree;

public:
    BIT(const vector<T>& arr) : n(arr.size()), data(arr.begin(), arr.end()), tree(n + 1){

        for(int i = 0; i < n; i ++)
            tree[i + 1]= data[i];

        for(int i = 1; i <= n; i ++){
            int parent = i + (i & -i);
            if(parent <= n) tree[parent] += tree[i];
        }
    }

    void add(int index, T v){
        assert(0 <= index && index < n);

        data[index] += v;

        index ++;
        for(;index <= n; index += (index & -index))
            tree[index] += v;
    }

    T query(int l, int r){
        assert(0 <= l && l < n);
        assert(0 <= r && r < n);
        assert(l <= r);
        return prefix_sum(r + 1) - prefix_sum(l);
    }

    void set(int index, T v){
        assert(0 <= index && index < n);
        add(index, v - data[index]);
    }

private:
    // r is 1-based
    T prefix_sum(int r){

        T res = 0;
        for(; r; r -= (r & -r))
            res += tree[r];
        return res;
    }
};

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> left(n, -1);
        int cur = -1;
        for(int i = 0; i < n; i ++){
            if(s[i] == '|') cur = i;
            left[i] = cur;
        }

        vector<int> right(n, n);
        cur = n;
        for(int i = n - 1; i >= 0; i --){
            if(s[i] == '|') cur = i;
            right[i] = cur;
        }

        vector<int> data(n, 0);
        for(int i = 0; i < n; i ++)
            if(s[i] == '*') data[i] = 1;
        BIT<int> tree(data);

        vector<int> res(queries.size(), 0);
        for(int i = 0; i < queries.size(); i ++){
            int ql = queries[i][0], qr = queries[i][1];
            int l = right[ql], r = left[qr];
            if(l <= r) res[i] = tree.query(l, r);
        }
        return res;
    }
};


int main() {

    return 0;
}
