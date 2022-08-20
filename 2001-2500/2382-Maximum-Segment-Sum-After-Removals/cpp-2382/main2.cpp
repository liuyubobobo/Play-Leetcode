/// Source : https://leetcode.com/problems/maximum-segment-sum-after-removals/
/// Author : liuyubobobo
/// Time   : 2022-08-20

#include <iostream>
#include <vector>

using namespace std;


/// Same idea with main.cpp, but has some optimization
/// Such as declare sum as a vector instead of map
/// ans no need to main sum_set but just just max_sum to keep the best result
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class UF{

private:
    vector<int> parent;

public:
    UF(int n) : parent(n){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    bool is_connected(int p, int q){
        return find(p) == find(q);
    }

    void union_elements(int p, int q){

        int p_root = find(p), q_root = find(q);

        if(p_root == q_root) return;

        parent[p_root] = q_root;
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {

        int n = nums.size();

        vector<long long> v(n);
        for(int i = 0; i < n; i ++) v[i] = nums[i];

        for(int index: removeQueries) v[index] = 0;

        UF uf(n);
        vector<long long> sum(n, 0);
        long long max_sum = 0;
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || (v[i] != 0) != (v[start] != 0)){
                if(v[start] != 0){
                    long long seg_sum = 0;
                    for(int j = start; j < i; j ++){
                        seg_sum += v[j];
                        uf.union_elements(start, j);
                    }
                    sum[uf.find(start)] = seg_sum;
                    max_sum = max(max_sum, seg_sum);
                }
                start = i;
            }

        vector<long long> res(n, max_sum);
        for(int i = n - 1; i > 0; i --){
            int index = removeQueries[i];
            long long new_seg_sum = nums[index];
            if(index - 1 >= 0 && v[index - 1] != 0){
                long long left_sum = sum[uf.find(index - 1)];
                new_seg_sum += left_sum;
                uf.union_elements(index, index - 1);
            }
            if(index + 1 < n && v[index + 1] != 0){
                long long right_sum = sum[uf.find(index + 1)];
                new_seg_sum += right_sum;
                uf.union_elements(index, index + 1);
            }

            sum[uf.find(index)] = new_seg_sum;
            max_sum = max(max_sum, new_seg_sum);
            res[i - 1] = max_sum;
            v[index] = nums[index];
        }
        return res;
    }
};


void print_vec(const vector<long long>& v){
    for(long long e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> nums1 = {1, 2, 5, 6, 1};
    vector<int> removeQueries1 = {0, 3, 2, 4, 1};
    print_vec(Solution().maximumSegmentSum(nums1, removeQueries1));
    // 14 7 2 2 0

    return 0;
}
