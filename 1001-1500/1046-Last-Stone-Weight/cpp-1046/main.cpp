/// Source : https://leetcode.com/problems/last-stone-weight/
/// Author : liuyubobobo
/// Time   : 2019-05-18

#include <iostream>
#include <vector>

using namespace std;


/// Simulation and keep sorting
/// Time Complexity: O(n * nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        sort(stones.begin(), stones.end());
        while(stones.size() > 1){
            int a = stones.back();
            stones.pop_back();
            int b = stones.back();
            stones.pop_back();

            if(a != b){
                stones.push_back(a - b);
                sort(stones.begin(), stones.end());
            }
        }

        if(stones.size()) return stones[0];
        return 0;
    }
};


int main() {

    return 0;
}