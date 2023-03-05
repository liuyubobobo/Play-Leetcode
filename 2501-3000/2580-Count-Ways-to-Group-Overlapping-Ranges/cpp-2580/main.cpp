/// Source : https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/description/
/// Author : liuyubobobo
/// Time   : 2023-03-04

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int countWays(vector<vector<int>>& ranges) {

        int n = ranges.size();
        sort(ranges.begin(), ranges.end());

        int cnt = 0, l = ranges[0][0], r = ranges[0][1];
        for(int i = 1; i <= n; i ++){
            if(i < n && overlapped(l, r, ranges[i][0], ranges[i][1])){
                l = min(l, ranges[i][0]);
                r = max(r, ranges[i][1]);
            }
            else{
                cnt ++;
                if(i < n) l = ranges[i][0], r = ranges[i][1];
            }
        }

        long long res = 1;
        for(int i = 0; i < cnt; i ++) res = res * 2ll % MOD;
        return res;
    }

private:
    bool overlapped(int l1, int r1, int l2, int r2){
        assert(l2 >= l1);
        return l1 <= l2 && l2 <= r1;
    }
};


int main() {

    return 0;
}
