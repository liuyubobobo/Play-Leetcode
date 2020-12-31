/// Source : https://leetcode.com/problems/moving-stones-until-consecutive-ii/
/// Author : liuyubobobo
/// Time   : 2019-05-19

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// For Upperbound: Mathematics
/// For Lowerbound: Sliding Window
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

private:
    int n;

public:
    vector<int> numMovesStonesII(vector<int>& stones) {

        n = stones.size();
        sort(stones.begin(), stones.end());
        return {get_min(stones), get_max(stones)};
    }

private:
    int get_min(const vector<int>& stones){

        int res = INT_MAX;
        int l = 0;
        for(int r = 0; r < n; r ++){
            while(stones[r] - stones[l] + 1 > n) l ++;
            if(r - l + 1 == n - 1 && stones[r] - stones[l] + 1 == n - 1)
                res = min(res, 2);
            else
                res = min(res, n - (r - l + 1));
        }
        return res;
    }

    int get_max(const vector<int>& stones){

        return max((stones[n - 1] - stones[1] + 1) - n + 1,
                   (stones[n - 2] - stones[0] + 1) - n + 1);
    }
};


int main() {

    return 0;
}