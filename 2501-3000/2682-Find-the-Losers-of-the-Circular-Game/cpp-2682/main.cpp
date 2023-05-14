/// Source : https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/
/// Author : liuyubobobo
/// Time   : 2023-05-13

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {

        vector<bool> visited(n, false);
        for(int i = 1, cur = 0; !visited[cur];i ++){
            visited[cur] = true;
            cur = (cur + i * k) % n;
        }

        vector<int> res;
        for(int i = 0; i < n; i ++) if(!visited[i]) res.push_back(i + 1);
        return res;
    }
};


int main() {


    return 0;
}
