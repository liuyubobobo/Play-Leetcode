/// Source : https://leetcode.com/problems/next-greater-element-iv/
/// Author : liuyubobobo
/// Time   : 2022-10-30

#include <iostream>
#include <vector>

using namespace std;


/// Mono Stack + ST + Binary Search
/// Time Complexity: O(n(logn)^2)
/// Space Complexity: O(nlogn)
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
    vector<int> secondGreaterElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> next(n, -1), s;
        for(int i = 0; i < n; i ++){
            while(!s.empty() && nums[i] > nums[s.back()])
                next[s.back()] = i, s.pop_back();
            s.push_back(i);
        }

        SparseTable<int> st(nums, [](int a, int b){return max(a, b);});
        vector<int> res(n, -1);
        for(int i = 0; i < n; i ++){
            int a = next[i];
            if(a == -1) continue;

            int l = a + 1, r = n;
            while(l < r){
                int mid = (l + r) / 2;
                if(st.query(a + 1, mid) > nums[i]) r = mid;
                else l = mid + 1;
            }
            res[i] = l == n ? -1 : nums[l];
        }
        return res;
    }
};


int main() {

    return 0;
}
