/// Source : https://leetcode.com/problems/jump-game-ii/
/// Author : liuyubobobo
/// Time   : 2021-07-27

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n + E)
/// Space Complexity: O(n)
class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        int s = 0, t = n - 1;
        vector<int> dis(n, -1);

        queue<int> q;
        q.push(0);
        dis[0] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;

            for(int i = 1; i <= nums[u] && u + i < n; i ++)
                if(dis[u + i] == -1){
                    dis[u + i] = dis[u] + 1;
                    q.push(u + i);
                }
        }
        return dis.back();
    }
};


int main() {

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << Solution().jump(nums1) << endl;
    // 2

    return 0;
}
