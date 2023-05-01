/// Source : https://leetcode.com/problems/make-array-empty/description/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;


/// Using BIT
/// Time Complexity: O(nlogn)
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

    BIT(int n): n(n), data(n, 0), tree(n + 1, 0){}

    void add(int index, T v){
        assert(0 <= index && index < n);

        data[index] += v;

        index ++;
        for(;index <= n; index += (index & -index))
            tree[index] += v;
    }

    T query(int l, int r){
        if(!(0 <= l && l < n) || !(0 <= r && r < n)) return 0;
        if(l > r) return 0;
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
    long long countOperationsToEmptyArray(vector<int>& nums) {

        int n = nums.size();
        vector<pair<int, int>> order(n);
        for(int i = 0; i < n; i ++) order[i] = {nums[i], i};
        sort(order.begin(), order.end());

        BIT<int> bit(vector<int>(n, 1));

        int front = 0;
        long long res = 0;
        for(const pair<int, int>& p: order){
            int index = p.second;
            if(index > front){
                res += bit.query(front, index - 1);
                bit.set(index, 0);
                res ++;
                front = (index + 1) % n;
            }
            else if(index < front){
                res += bit.query(front, n - 1);
                res += bit.query(0, index - 1);
                bit.set(index, 0);
                res ++;
                front = (index + 1) % n;
            }
            else{
                bit.set(index, 0);
                res ++;
                front = (index + 1) % n;
            }
        }
        return res;

    }
};


int main() {

    vector<int> nums1 = {-15, -19, 5};
    cout << Solution().countOperationsToEmptyArray(nums1) << endl;
    // 5

    return 0;
}
