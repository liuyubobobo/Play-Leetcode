/// Source : https://leetcode.com/problems/two-best-non-overlapping-events/
/// Author : liuyubobobo
/// Time   : 2021-10-30

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());

        int n = events.size();
        vector<int> max_value(n, events.back()[2]);
        for(int i = n - 2; i >= 0; i --)
            max_value[i] = max(events[i][2], max_value[i + 1]);

        int res = 0;
        for(int i = 0; i < n; i ++){
            res = max(res, events[i][2]);

            vector<int> t = {events[i][1] + 1, INT_MIN, INT_MIN};
            vector<vector<int>>::iterator iter = lower_bound(events.begin(), events.end(), t);
            if(iter != events.end()){
                int index = iter - events.begin();
                res = max(res, events[i][2] + max_value[index]);
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
