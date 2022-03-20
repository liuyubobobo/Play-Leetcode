/// Source : https://leetcode.com/problems/maximum-points-in-an-archery-competition/
/// Author : liuyubobobo
/// Time   : 2022-03-19

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Greedy
/// Time Complexity: O(2^12 * 12)
/// Space Complexity: O(12)
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {

        int best_score = 0;
        vector<int> res(12, 0);
        res[0] = numArrows;

        for(int state = 1; state < (1 << 12); state ++){
            vector<int> tres(12, 0);
            int tscore = 0;
            for(int i = 0; i < 12; i ++)
                if(state & (1 << i)){
                    tres[i] = aliceArrows[i] + 1;
                    tscore += i;
                }
            if(tscore <= best_score) continue;

            int sum = accumulate(tres.begin(), tres.end(), 0);
            if(sum > numArrows) continue;

            for(int i = 0; i < 12; i ++)
                if(state & (1 << i)){
                    tres[i] += (numArrows - sum);
                    break;
                }

            best_score = tscore;
            res = tres;
        }
        return res;
    }
};


int main() {

    return 0;
}
