/// Source : https://leetcode.com/problems/poor-pigs/
/// Author : liuyubobobo
/// Time   : 2019-05-02

#include <iostream>
#include <cmath>

using namespace std;


/// Mathematics
/// A better explanation than official solution if here:
/// https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution
///
/// Time Complexity: O(log(buckets))
/// Space Complexity: O(1)
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {

        int res = 0;
        while((int)pow(minutesToTest / minutesToDie + 1, res) < buckets)
            res ++;
        return res;
    }
};


int main() {

    return 0;
}