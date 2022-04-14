/// Source : https://leetcode.com/problems/count-positions-on-street-with-required-brightness/
/// Author : liuyubobobo
/// Time   : 2022-04-13

#include <iostream>
#include <vector>

using namespace std;


/// Diff Array
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {

        vector<int> diff(n + 1, 0);
        for(const vector<int>& light: lights){
            int pos = light[0], range = light[1];
            int l = max(0, pos - range), r = min(n - 1, pos + range);

            diff[l] += 1, diff[r + 1] -= 1;
        }

        int cur = 0, res = 0;
        for(int i = 0; i < n; i ++){
            cur += diff[i];
            res += (cur >= requirement[i]);
        }
        return res;
    }
};


int main() {

    return 0;
}
