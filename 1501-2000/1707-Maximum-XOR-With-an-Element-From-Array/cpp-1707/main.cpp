/// Source : https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
/// Author : liuyubobobo
/// Time   : 2020-12-29

#include <iostream>
#include <vector>

using namespace std;


/// Trie
/// Time Complexity: O(n + q)
/// Space Complexity: O(n)
class Solution {

private:
    int trie[2000000][2];
    int sz = 0;
    const int D = 30;

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());
        for(int i = 0; i < queries.size(); i ++)
            queries[i].push_back(i);

        sort(queries.begin(), queries.end(), [](const vector<int>& q1, const vector<int>& q2){
            return q1[1] < q2[1];
        });

        memset(trie, -1, sizeof(trie));
        sz = 1;

        int i = 0;
        vector<int> res(queries.size());
        for(const vector<int>& q: queries){

            while(i < nums.size() && nums[i] <= q[1])
                insert(nums[i ++]);

            if(sz == 1) res[q[2]] = -1;
            else res[q[2]] = query_xor(q[0]) ^ q[0];
        }
        return res;
    }

private:
    int query_xor(int num){

        int cur = 0, res = 0;
        for(int i = 0; i < D; i ++){
            int e = !!(num & (1 << (D - i - 1)));
            if(trie[cur][1 - e] != -1){
                res = res * 2 + 1 - e;
                cur = trie[cur][1 - e];
            }
            else{
                res = res * 2 + e;
                cur = trie[cur][e];
            }
        }
        return res;
    }

    void insert(int num){

        int cur = 0;
        for(int i = 0; i < D; i ++){
            int e = !!(num & (1 << (D - i - 1)));
            if(trie[cur][e] == -1)
                trie[cur][e] = sz ++;
            cur = trie[cur][e];
        }
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {0, 1, 2, 3, 4};
    vector<vector<int>> query1 = {{3, 1}, {1, 3}, {5, 6}};
    print_vec(Solution().maximizeXor(nums1, query1));
    // 3 3 7

    vector<int> nums2 = {5, 2, 4, 6, 6, 3};
    vector<vector<int>> query2 = {{12, 4}, {8, 1}, {6, 3}};
    print_vec(Solution().maximizeXor(nums2, query2));
    // 15 -1 5

    return 0;
}
