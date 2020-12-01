/// Source : https://leetcode.com/problems/find-the-most-competitive-subsequence/
/// Author : liuyubobobo
/// Time   : 2020-11-30

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int n = nums.size();
        for(int i = 0; i < n - k; i ++)
            pq.push({nums[i], i});

        vector<int> res(k);
        int l = 0, r = n - k;
        for(int i = 0; i < k; i ++){

            pq.push({nums[r], r});
            r ++;

            while(!pq.empty() && pq.top().second < l) pq.pop();

            assert(!pq.empty());
            res[i] = pq.top().first;
            l = pq.top().second + 1;
            pq.pop();
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {3, 5, 2, 6};
    print_vec(Solution().mostCompetitive(nums1, 2));
    // 2 6

    vector<int> nums2 = {2,4,3,3,5,4,9,6};
    print_vec(Solution().mostCompetitive(nums2, 4));
    // 2 3 3 4

    return 0;
}