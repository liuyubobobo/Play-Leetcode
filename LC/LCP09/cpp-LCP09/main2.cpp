/// Source : https://leetcode-cn.com/problems/zui-xiao-tiao-yue-ci-shu/
/// Author : liuyubobobo
/// Time   : 2020-04-19

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int minJump(vector<int>& jump) {

        int n = jump.size();
        vector<int> step(n + 1, -1);
        step[0] = 0;
        queue<int> q;
        q.push(0);
        int max_left = -1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            int right = cur + jump[cur];
            if(right >= n) return 1 + step[cur];
            if(step[right] == -1){
                step[right] = 1 + step[cur];
                q.push(right);
            }

            for(int left = cur - 1; left > max_left; left --){
                step[left] = 1 + step[cur];
                q.push(left);
            }
            max_left = max(max_left, cur);
        }
        assert(false);
        return -1;
    }
};


int main() {

    vector<int> jump1 = {2, 5, 1, 1, 1, 1};
    cout << Solution().minJump(jump1) << endl;
    // 3

    vector<int> jump2 = {2, 1, 2, 100, 2, 1, 1, 1, 1};
    cout << Solution().minJump(jump2) << endl;
    // 4

    return 0;
}
