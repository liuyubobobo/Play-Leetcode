/// Source : https://leetcode.com/problems/brick-wall/
/// Author : liuyubobobo
/// Time   : 2021-04-22

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        unordered_map<int, int> map;
        for(int i = 0; i < wall.size(); i ++){
            int sum = 0;
            for(int j = 0; j < wall[i].size(); j ++){
                sum += wall[i][j];
                if(j != wall[i].size() - 1)
                    map[sum] ++;
            }
        }

        int maxf = 0;
        for(const pair<int, int>& p: map)
            maxf = max(maxf, p.second);
        return wall.size() - maxf;
    }
};


int main() {

    return 0;
}
