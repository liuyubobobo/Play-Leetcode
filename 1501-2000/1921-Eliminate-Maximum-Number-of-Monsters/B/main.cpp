/// Source : https://leetcode.com/problems/4sum-ii/
/// Author : liuyubobobo
/// Time   : 2021-07-03

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

        int n = dist.size();
        vector<int> t(n);
        for(int i = 0; i < n; i ++)
            t[i] = dist[i] / speed[i] + !!(dist[i] % speed[i]);

        sort(t.begin(), t.end());

        int cur = 0;
        for(int i = 0; i < n; i ++, cur ++)
            if(cur >= t[i]) return i;
        return n;
    }
};


int main() {

    vector<int> dist1 = {1, 3, 4}, speed1 = {1, 1, 1};
    cout << Solution().eliminateMaximum(dist1, speed1) << endl;
    // 3

    vector<int> dist2 = {1, 1, 2, 3}, speed2 = {1, 1, 1, 1};
    cout << Solution().eliminateMaximum(dist2, speed2) << endl;
    // 1

    vector<int> dist3 = {3, 2, 4}, speed3 = {5, 3, 2};
    cout << Solution().eliminateMaximum(dist3, speed3) << endl;
    // 1

    return 0;
}
