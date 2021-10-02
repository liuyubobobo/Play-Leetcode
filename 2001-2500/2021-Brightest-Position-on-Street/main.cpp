/// Source : https://leetcode.com/problems/brightest-position-on-street/
/// Author : liuyubobobo
/// Time   : 2021-10-02

#include <iostream>
#include <vector>

using namespace std;


/// Sweep line
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {

        const int START = 0, END = 1;

        int n = lights.size();
        vector<pair<int, int>> v(2 * n);
        for(int i = 0; i < n; i ++){
            v[2 * i] = {lights[i][0] - lights[i][1], START};
            v[2 * i + 1] = {lights[i][0] + lights[i][1], END};
        }

        sort(v.begin(), v.end());

        int cur_brightness = 0, max_brightness = 0, res = INT_MIN;
        for(const pair<int, int>& p: v)
            if(p.second == START){
                cur_brightness ++;
                if(cur_brightness > max_brightness)
                    max_brightness = cur_brightness, res = p.first;
            }
            else
                cur_brightness --;
        return res;
    }
};


int main() {

    vector<vector<int>> lights = {{-3, 2}, {1, 2}, {3, 3}};
    cout << Solution().brightestPosition(lights) << endl;
    // -1

    return 0;
}
