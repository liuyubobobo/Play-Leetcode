/// Source : https://leetcode.com/problems/maximum-split-of-positive-even-integers/
/// Author : liuyubobobo
/// Time   : 2022-02-19

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(sqrt(sum))
/// Space Complexity: O(1)
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {

        if(finalSum % 2ll) return {};

        vector<long long> res;
        long long cur = 2;
        while(finalSum >= cur){
            res.push_back(cur);
            finalSum -= cur;
            cur += 2;
        }

        if(finalSum == 0) return res;
        res.back() += finalSum;
        return res;
    }
};


int main() {

    return 0;
}
