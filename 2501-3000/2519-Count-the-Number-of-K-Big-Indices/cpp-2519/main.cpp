/// Source : https://leetcode.com/problems/count-the-number-of-k-big-indices/
/// Author : liuyubobobo
/// Time   : 2022-12-28

#include <iostream>
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

    void add(int index, T v){
        assert(0 <= index && index < n);

        data[index] += v;

        index ++;
        for(;index <= n; index += (index & -index))
            tree[index] += v;
    }

    T query(int l, int r){
        if(!(0 <= l && l < n) || !(0 <= r && r < n) || !(l <= r)) return 0;
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
    int kBigIndices(vector<int>& nums, int k) {

        int maxv = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        BIT<int> bit1(vector<int>(maxv + 1, 0));
        vector<int> left(n, 0);
        for(int i = 0; i < n; i ++){
            left[i] = bit1.query(0, nums[i] - 1);
            bit1.add(nums[i], 1);
        }

        BIT<int> bit2(vector<int>(maxv + 1, 0));
        vector<int> right(n, 0);
        for(int i = n - 1; i >= 0; i --){
            right[i] = bit2.query(0, nums[i] - 1);
            bit2.add(nums[i], 1);
        }

        int res = 0;
        for(int i = 0; i < n; i ++)
            res += (left[i] >= k && right[i] >= k);
        return res;
    }
};


int main() {

    return 0;
}
