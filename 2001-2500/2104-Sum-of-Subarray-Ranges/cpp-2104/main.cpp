/// Source : https://leetcode.com/problems/sum-of-subarray-ranges/
/// Author : liuyubobobo
/// Time   : 2021-12-11

#include <iostream>
#include <vector>

using namespace std;


/// ST
/// Time Complexity: O(nlogn + n^2)
/// Space Complexity: O(n)
template<typename T>
class SparseTable{

private:
    int n;
    vector<vector<T>> table;
    vector<int> log2;
    T (*combine)(T a, T b);

public:
    SparseTable(const vector<T>& data, T (*combine)(T a, T b)): n(data.size()), log2(n + 1, 1){

        this->combine = combine;

        int len = 2, k = 1;
        for(int i = 1; i <= n; i ++){
            if(i >= len) len <<= 1, k ++;
            log2[i] = k;
        }

        int K = log2[n];
        table = vector<vector<T>>(K, vector<T>(n));

        for(int i = 0; i < n; i ++)
            table[0][i] = data[i];

        for(int k = 1; k < K; k ++)
            for(int i = 0; i + (1 << (k - 1)) < n; i ++)
                table[k][i] = combine(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
    }

    T query(int l, int r){

        int k = log2[r - l + 1];
        return combine(table[k - 1][l], table[k - 1][r + 1 - (1 << (k - 1))]);
    }
};

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        auto max_f = [](int a, int b){return max(a, b);};
        auto min_f = [](int a, int b){return min(a, b);};
        SparseTable<int> st_min(nums, min_f);
        SparseTable<int> st_max(nums, max_f);

        int n = nums.size();
        long long res = 0;
        for(int l = 0; l < n; l ++)
            for(int r = l + 1; r < n; r ++)
                res += (long long)st_max.query(l, r) - st_min.query(l, r);
        return res;
    }
};


int main() {

    return 0;
}
