/// Source : https://leetcode.com/problems/maximum-subsequence-score/description/
/// Author : liuyubobobo
/// Time   : 2023-01-21

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();

        vector<pair<long long, long long>> v(n);
        for(int i = 0; i < n; i ++) v[i] = {nums1[i], nums2[i]};

        sort(v.begin(), v.end(),
             [](const pair<long long, long long>& p1, const pair<long long, long long>& p2){
            return p1.second < p2.second;
        });

        priority_queue<long long, vector<long long>, greater<>> pq;
        long long sum = 0;
        for(int i = n - 1; i >= n - k; i --)
            pq.push(v[i].first), sum += v[i].first;

        long long res = v[n - k].second * sum;
        for(int i = n - k - 1; i >= 0; i --){
            long long t = pq.top();
            pq.pop();
            sum -= t;
            pq.push(v[i].first);
            sum += v[i].first;
            res = max(res, v[i].second * sum);
        }
        return res;
    }
};


int main() {

    return 0;
}
