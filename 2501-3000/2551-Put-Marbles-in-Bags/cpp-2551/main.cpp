/// Source : https://leetcode.com/problems/put-marbles-in-bags/description/
/// Author : liuyubobobo
/// Time   : 2023-01-29

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {

        int n = weights.size();

        vector<long long> v;
        for(int i = 0; i + 1 < n; i ++) v.push_back(weights[i] + weights[i + 1]);
        sort(v.begin(), v.end());

        long long maxv = 0, minv = 0;
        for(int i = (int)v.size() - 1, j = 0; j < k - 1; j ++, i --) maxv += v[i];
        for(int i = 0, j = 0; j < k - 1; j ++, i ++) minv += v[i];

        return maxv - minv;
    }
};


int main() {

    return 0;
}
