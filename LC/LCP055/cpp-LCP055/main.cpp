/// Source : https://leetcode-cn.com/problems/PTXy4P/
/// Author : liuyubobobo
/// Time   : 2022-04-23

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(|fruits|)
/// Space Complexity: O(1)
class Solution {
public:
    int getMinimumTime(vector<int>& time, vector<vector<int>>& fruits, int limit) {

        int res = 0;
        for(const vector<int>& fruit: fruits){
            int type = fruit[0], num = fruit[1];
            res += (num / limit + !!(num % limit)) * time[type];
        }
        return res;
    }
};


int main() {

    return 0;
}
