/// Source : https://leetcode.com/problems/distribute-candies-to-people/
/// Author : liuyubobobo
/// Time   : 2019-06-29

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(sqrt(candies))
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        vector<int> res(num_people, 0);
        for(int c = 1, i = 0; candies; c ++, i ++){
            int x = min(c, candies);
            res[i % num_people] += x;
            candies -= x;
        }
        return res;
    }
};


int main() {

    return 0;
}