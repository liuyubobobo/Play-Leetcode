/// Source : https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
/// Author : liuyubobobo
/// Time   : 2020-10-31

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// TreeSet
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        set<int> set;
        for(const vector<int>& p: points) set.insert(p[0]);

        if(set.size() <= 1) return 0;

        int last = *set.begin(), res = 0;
        for(int e: set){
            res = max(res, e - last);
            last = e;
        }
        return res;
    }
};


int main() {

    return 0;
}
