/// Source : https://leetcode.com/problems/teemo-attacking/
/// Author : liuyubobobo
/// Time   : 2021-11-09

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        int n = timeSeries.size();
        int start = timeSeries[0], end = timeSeries[0] + duration, res = 0;
        for(int i = 1; i <= n; i ++)
            if(i == n || timeSeries[i] > end){
                res += end - start;
                if(i < n) start = timeSeries[i], end = timeSeries[i] + duration;
                else break;
            }
            else end = timeSeries[i] + duration;
        return res;
    }
};


int main() {

    vector<int> t1 = {1, 2};
    cout << Solution().findPoisonedDuration(t1, 2) << endl;
    // 3

    return 0;
}
