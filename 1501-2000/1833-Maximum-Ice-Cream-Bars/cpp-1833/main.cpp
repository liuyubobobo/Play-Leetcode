/// Source : https://leetcode.com/problems/maximum-ice-cream-bars/
/// Author : liuyubobobo
/// Time   : 2021-04-17

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(), costs.end());

        int res = 0;
        for(int e: costs)
            if(e <= coins){
                res ++;
                coins -= e;
            }
        return res;
    }
};


int main() {

    return 0;
}
