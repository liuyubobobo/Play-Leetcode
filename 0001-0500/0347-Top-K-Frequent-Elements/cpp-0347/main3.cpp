/// Source : https://leetcode.com/problems/top-k-frequent-elements/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;

/// Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        assert(k > 0);

        // 统计每个元素出现的频率
        unordered_map<int,int> freq;
        for(int i = 0 ; i < nums.size() ; i ++ )
            freq[nums[i]] ++;

        assert(k <= freq.size());

        // 扫描freq,维护当前出现频率最高的k个元素
        // 在优先队列中,按照频率排序,所以数据对是 (频率,元素) 的形式
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(const pair<int, int>& p: freq){
            if(pq.size() == k && p.second > pq.top().first) pq.pop();
            if(pq.size() < k) pq.push(make_pair(p.second , p.first));
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    print_vec(Solution().topKFrequent(nums1, 2));

    vector<int> nums2 = {3, 0, 1, 0};
    print_vec(Solution().topKFrequent(nums2, 1));
    // 0

    return 0;
}