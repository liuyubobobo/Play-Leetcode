/// Source : https://leetcode.com/problems/distribute-candies-to-people/
/// Author : liuyubobobo
/// Time   : 2019-07-07

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Mathematics
/// See here for details: https://leetcode.com/problems/distribute-candies-to-people/solution/
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        int p = (int)(sqrt(2 * candies + 0.25) - 0.5);
        int last_remaining = candies - p * (p + 1) / 2;
        int rows = p / num_people, cols = p % num_people;

        vector<int> res(num_people);
        for(int i = 0; i < num_people; i ++){
            res[i] = (i + 1) * rows + rows * (rows - 1) / 2 * num_people;
            if(i < cols) res[i] += (i + 1) + rows * num_people;
        }
        res[cols] += last_remaining;

        return res;
    }
};


int main() {

    return 0;
}