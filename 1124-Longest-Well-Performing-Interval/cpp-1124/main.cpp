/// Source : https://leetcode.com/problems/longest-well-performing-interval/
/// Author : liuyubobobo
/// Time   : 2019-07-13

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int longestWPI(vector<int>& hours) {

        for(int& e: hours)
            e = (e > 8 ? 1 : 0);

        int n = hours.size();
        vector<int> presum(n + 1, 0);
        for(int i = 1; i <= n; i ++)
            presum[i] = presum[i - 1] + hours[i - 1];

        int best = 0;
        for(int end = 0; end < n; end ++)
            for(int start = 0; start <= end && end - start + 1 > best; start ++)
                if((presum[end + 1] - presum[start]) * 2 > end - start + 1)
                    best = max(best, end - start + 1);
        return best;
    }
};


int main() {

    return 0;
}