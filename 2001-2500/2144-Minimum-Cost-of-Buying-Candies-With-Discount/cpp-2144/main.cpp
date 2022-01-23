/// Source : https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
/// Author : liuyubobobo
/// Time   : 2022-01-22

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin(), cost.end(), greater<int>());

        int res = 0;
        for(int i = 0; i < cost.size(); i += 3){
            res += cost[i];
            if(i + 1 < cost.size()) res += cost[i + 1];
        }
        return res;
    }
};


int main() {

    return 0;
}
