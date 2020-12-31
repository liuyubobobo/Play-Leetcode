/// Source : https://leetcode.com/problems/longest-well-performing-interval/
/// Author : liuyubobobo
/// Time   : 2019-07-15

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Presum + Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int longestWPI(vector<int>& hours) {

        for(int& e: hours)
            e = (e > 8 ? 1 : -1);

        int n = hours.size();
        vector<int> presum(n + 1, 0);
        for(int i = 1; i <= n; i ++)
            presum[i] = presum[i - 1] + hours[i - 1];

        unordered_map<int, int> pos;
        int res = 0;
        for(int i = 1; i <= n; i ++)
            if(presum[i] > 0) res = max(res, i);
            else{
                if(!pos.count(presum[i])) pos[presum[i]] = i;
                if(pos.count(presum[i] - 1)) res = max(res, i - pos[presum[i] - 1]);
            }
        return res;
    }
};


int main() {

    vector<int> hours = {9,9,6,0,6,6,9};
    cout << Solution().longestWPI(hours) << endl;

    return 0;
}