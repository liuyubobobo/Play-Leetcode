/// Source : https://leetcode.com/problems/maximum-number-of-robots-within-budget/
/// Author : liuyubobobo
/// Time   : 2022-09-03

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// ST(query range max) + Binary Seach
/// Time Complexity: O(n * logn * logn)
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
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {

        int n = chargeTimes.size();
        assert(runningCosts.size() == n);

        SparseTable<int> st(chargeTimes, [](int a, int b){return max(a, b);});
        vector<long long> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + runningCosts[i];

        int res = 0;
        for(int start = 0; start + res < n; start ++){

            // check [start, start + res], len = res + 1
            // if not work, no need to search from start
            if((presum[start + res + 1] - presum[start]) * (res + 1) + st.query(start, start + res) > budget)
                continue;

            int end_l = start + res, end_r = n - 1;
            while(end_l < end_r){
                int end_mid = (end_l + end_r + 1) / 2;

                // [start, end_mid]
                long long t = (presum[end_mid + 1] - presum[start]) * (end_mid - start + 1) + st.query(start, end_mid);
                if(t <= budget)
                    end_l = end_mid;
                else
                    end_r = end_mid - 1;
            }
            res = max(res, end_l - start + 1);
        }
        return res;
    }
};


int main() {

    return 0;
}
