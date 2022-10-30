/// Source : https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/
/// Author : liuyubobobo
/// Time   : 2022-10-29

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int averageValue(vector<int>& nums) {

        int total = 0, cnt = 0;
        for(int e: nums)
            if(e % 6 == 0) total += e, cnt ++;
        return cnt == 0 ? 0 : total / cnt;
    }
};


int main() {

    return 0;
}
