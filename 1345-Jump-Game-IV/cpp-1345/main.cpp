/// Source : https://leetcode.com/problems/jump-game-iv/
/// Author : liuyubobobo
/// Time   : 2017-05-05

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n + m)
/// Space Complexity: O(n)
class Solution {
public:
    int minJumps(vector<int>& arr) {

        if(arr.size() == 1) return 0;

        map<int, vector<int>> pos;
        for(int i = 0; i < arr.size(); i ++)
            pos[arr[i]].push_back(i);

        vector<int> step(arr.size(), -1);
        queue<int> q;
        q.push(0);
        step[0] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur == arr.size() - 1) return step[cur];

            if(cur - 1 >= 0 && step[cur - 1] == -1)
                q.push(cur - 1), step[cur - 1] = step[cur] + 1;
            if(cur + 1 < arr.size() && step[cur + 1] == -1)
                q.push(cur + 1), step[cur + 1] = step[cur] + 1;
            for(int p: pos[arr[cur]])
                if((p < cur - 1 || p > cur + 1) && step[p] == -1)
                    q.push(p), step[p] = step[cur] + 1;
            pos.erase(arr[cur]);
        }
        return -1;
    }
};


int main() {

    vector<int> arr1 = {100,-23,-23,404,100,23,23,23,3,404};
    cout << Solution().minJumps(arr1) << endl;
    // 3

    return 0;
}
