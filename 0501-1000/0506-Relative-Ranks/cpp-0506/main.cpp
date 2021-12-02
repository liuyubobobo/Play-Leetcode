/// Source : https://leetcode.com/problems/relative-ranks/
/// Author : liuyubobobo
/// Time   : 2021-12-02

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int n = score.size();
        vector<pair<int, int>> data(n);
        for(int i = 0; i < n; i ++)
            data[i] = {score[i], i};

        sort(data.begin(), data.end(), greater<pair<int, int>>());

        vector<string> res(n);

        if(n >= 1) res[data[0].second] = "Gold Medal";
        if(n >= 2) res[data[1].second] = "Silver Medal";
        if(n >= 3) res[data[2].second] = "Bronze Medal";
        for(int i = 3; i < n; i ++) res[data[i].second] = to_string(i + 1);
        return res;
    }
};


int main() {

    return 0;
}
