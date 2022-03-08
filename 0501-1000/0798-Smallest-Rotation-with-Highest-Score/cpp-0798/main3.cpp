/// Source : https://leetcode.com/problems/smallest-rotation-with-highest-score/
/// Author : liuyubobobo
/// Time   : 2022-03-08

#include <iostream>
#include <vector>

using namespace std;


/// Using BIT (as Sort List)
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
//        assert(0 <= index && index < n);

        if(index < 0) return;
        data[index] += v;

        index ++;
        for(;index <= n; index += (index & -index))
            tree[index] += v;
    }

    T query(int l, int r){
//        assert(0 <= l && l < n);
//        assert(0 <= r && r < n);
//        assert(l <= r);
        return prefix_sum(r + 1) - prefix_sum(l);
    }

    void set(int index, T v){
//        assert(0 <= index && index < n);
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
    int bestRotation(vector<int>& nums) {

        const int MAXN = 2e5;
        BIT<int> bit(vector<int>(MAXN, 0));

        int n = nums.size();
        for(int i = 0; i < n; i ++)
            bit.add(-(nums[i] - i), 1);

        int best_score = 0, k = 0;
        for(int i = 0; i < n; i ++){
            int score = bit.query(i, MAXN - 1);
//            cout << "k : " << i << " score : " << score << '\n';

            if(score > best_score) best_score = score, k = i;

            bit.add(-(nums[i] - i), -1);
            bit.add(-(nums[i] - (n - 1) - (i + 1)), 1);
        }
        return k;
    }
};


int main() {

    vector<int> nums1 = {2, 3, 1, 4, 0};
    cout << Solution().bestRotation(nums1) << '\n';
    // 3

    return 0;
}
