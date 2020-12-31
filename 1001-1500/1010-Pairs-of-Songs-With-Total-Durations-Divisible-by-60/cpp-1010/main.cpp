/// Source : https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
/// Author : liuyubobobo
/// Time   : 2019-03-16

#include <iostream>
#include <vector>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        vector<int> rem(60, 0);
        for(int t: time) rem[t % 60] ++;

        long long res = 0;
        if(rem[0]) res += (long long)rem[0] * (rem[0] - 1) / 2;
        if(rem[30]) res += (long long)rem[30] * (rem[30] - 1) / 2;
        for(int i = 1; i < 30; i ++)
            res += (long long)rem[i] * rem[60 - i];
        return res;
    }
};


int main() {

    return 0;
}