/// Source : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        vector<bool> res;
        int maxv = *max_element(candies.begin(), candies.end());
        for(int e: candies)
            res.push_back(e + extraCandies >= maxv);
        return res;
    }
};


int main() {

    return 0;
}
