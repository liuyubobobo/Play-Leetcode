/// Source : https://leetcode.com/problems/distribute-candies/
/// Author : liuyubobobo
/// Time   : 2021-03-01

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        unordered_map<int, int> f;
        for(int e: candyType) f[e] ++;

        return min(candyType.size() / 2, f.size());
    }
};


int main() {

    return 0;
}
