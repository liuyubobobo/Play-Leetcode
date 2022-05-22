/// Source : https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
/// Author : liuyubobobo
/// Time   : 2022-05-21

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {

        int n = capacity.size();
        for(int i = 0; i < n; i ++)
            capacity[i] -= rocks[i];

        sort(capacity.begin(), capacity.end());
        for(int i = 0; i < n; i ++)
            if(capacity[i] <= additionalRocks){
                additionalRocks -= capacity[i];
                capacity[i] = 0;
            }

        int res = 0;
        for(int e: capacity) res += e == 0;
        return res;
    }
};


int main() {

    return 0;
}
