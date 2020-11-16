/// Source : https://leetcode.com/problems/minimum-jumps-to-reach-home/
/// Author : liuyubobobo
/// Time   : 2020-11-16

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// BFS
/// Time Complexity:
class Solution {

public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

        unordered_set<int> no(forbidden.begin(), forbidden.end());

        queue<int> q; // pos * 2 + canback
        unordered_map<int, int> dis;

        q.push(1);
        dis[1] = 0;

        while(!q.empty()){

            int cur = q.front() / 2, canback = q.front() % 2;
            q.pop();

            if(cur == x) return dis[cur * 2 + canback];

            if(cur + a <= 6000 && !no.count(cur + a) && !dis.count((cur + a) * 2 + 1)){
                dis[(cur + a) * 2 + 1] = dis[cur * 2 + canback] + 1;
                q.push(2 * (cur + a) + 1);
            }

            if(cur - b >= 0 && canback && !no.count(cur - b) && !dis.count((cur - b) * 2)){
                dis[(cur - b) * 2] = dis[cur * 2 + canback] + 1;
                q.push(2 * (cur - b));
            }
        }
        return -1;
    }
};


int main() {

    vector<int> forbidden1 = {14, 4, 18, 1, 15};
    cout << Solution().minimumJumps(forbidden1, 3, 15, 9) << endl;
    // 3

    vector<int> forbidden2 = {8,3,16,6,12,20};
    cout << Solution().minimumJumps(forbidden2, 15, 13, 11) << endl;
    // -1

    vector<int> forbidden3 = {1,6,2,14,5,17,4};
    cout << Solution().minimumJumps(forbidden3, 16, 9, 7) << endl;
    // 2

    vector<int> forbidden4 = {5,2,10,12,18};
    cout << Solution().minimumJumps(forbidden4, 8, 6, 16) << endl;
    // 2

    vector<int> forbidden5 = {162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98};
    cout << Solution().minimumJumps(forbidden5, 29, 98, 80) << endl;
    // 121

    return 0;
}
