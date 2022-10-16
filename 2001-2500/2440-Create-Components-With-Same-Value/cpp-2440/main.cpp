/// Source : https://leetcode.cn/problems/create-components-with-same-value/
/// Author : liuyubobobo
/// Time   : 2022-10-16

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <queue>

using namespace std;


/// Topological Sort
/// Time Complexity: O(sqrt(sum) * n)
/// Space Complexity: O(n)
class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> D;
        for(int i = 1; i * i <= sum; i ++)
            if(sum % i == 0){
                D.push_back(i);
                if(i * i < sum) D.push_back(sum / i);
            }
        sort(D.begin(), D.end());

        int n = nums.size();
        vector<list<int>> g(n);
        vector<int> degrees(n, 0);
        for(const vector<int>& edge: edges){
            int a = edge[0], b = edge[1];
            g[a].push_back(b), g[b].push_back(a);
            degrees[a] ++, degrees[b] ++;
        }

        for(int d: D){
            if(ok(n, g, degrees, nums, d)){
                return sum / d - 1;
            }
        }
        assert(false);
        return -1;
    }

private:
    bool ok(int n, const vector<list<int>>& g,
            vector<int> degrees, vector<int> nums, int d){

        if(n == 1) return nums[0] == d;

        queue<int> q;
        vector<bool> inqueue(n, false);
        vector<bool> over(n, false);
        for(int i = 0; i < n; i ++)
            if(degrees[i] == 1) q.push(i), inqueue[i] = true;

        while(q.size() > 1){
            int cur = q.front(); q.pop();

            if(nums[cur] > d) return false;

            for(int next: g[cur]){
                if(over[next]) continue;
                degrees[next] --;
                degrees[cur] --;

                if(nums[cur] < d) nums[next] += nums[cur];
                if(degrees[next] == 1 && !inqueue[next]){
                    inqueue[next] = true;
                    q.push(next);
                }
            }
            over[cur] = true;
        }
        return nums[q.front()] == d;
    }
};


int main() {

//    vector<int> nums1 = {6,2,2,2,6};
//    vector<vector<int>> edges1 = {{0,1},{1,2},{1,3},{3,4}};
//    cout << Solution().componentValue(nums1, edges1) << '\n';
//    // 2

    vector<int> nums2 = {1};
    vector<vector<int>> edges2 = {};
    cout << Solution().componentValue(nums2, edges2) << '\n';
    // 2

    return 0;
}
