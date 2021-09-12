/// Source : https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/
/// Author : liuyubobobo
/// Time   : 2021-09-12

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {

        int n = parents.size();
        vector<int> res(n, 1);

        vector<int>::iterator iter = find(nums.begin(), nums.end(), 1);
        if(iter == nums.end())
            return res;

        vector<vector<int>> tree(n);
        for(int i = 1; i < n; i ++)
            tree[i].push_back(parents[i]), tree[parents[i]].push_back(i);

        int cur = iter - nums.begin();
        vector<bool> visited(100005, false);
        int v = 1;
        while(cur != -1){
            dfs(tree, nums, cur, parents[cur], visited);
            while(visited[v]) v ++;
            res[cur] = v;
            cur = parents[cur];
        }
        return res;
    }

private:
    void dfs(const vector<vector<int>>& tree, vector<int>& nums,
             int u, int p, vector<bool>& visited){

        visited[nums[u]] = true;

        for(int v: tree[u])
            if(v != p && !visited[nums[v]])
                dfs(tree, nums, v, u, visited);
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << endl;
}

int main() {

    vector<int> parents1 = {-1,0,0,2}, nums1 = {1,2,3,4};
    print_vec(Solution().smallestMissingValueSubtree(parents1, nums1));
    // 5 1 1 1

    vector<int> parents2 = {-1,0,1,0,3,3}, nums2 = {5,4,6,2,1,3};
    print_vec(Solution().smallestMissingValueSubtree(parents2, nums2));
    // 7,1,1,4,2,1

    vector<int> parents3 = {-1,2,3,0,2,4,1}, nums3 = {2,3,4,5,6,7,8};
    print_vec(Solution().smallestMissingValueSubtree(parents3, nums3));
    // 1,1,1,1,1,1,1

    return 0;
}
