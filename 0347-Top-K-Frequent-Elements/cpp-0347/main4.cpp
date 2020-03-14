/// Source : https://leetcode.com/problems/top-k-frequent-elements/description/
/// Author : liuyubobobo
/// Time   : 2020-03-13

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <set>

using namespace std;

/// Priority Queue for n-k elements
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

        // 扫描freq,维护当前出现频率最低的 n - k 个元素
        // 在优先队列中,按照频率排序,所以数据对是 (频率,元素) 的形式
        priority_queue<pair<int,int>> pq;
        for(const pair<int, int>& p: freq){
            if(freq.size() - k && pq.size() == freq.size() - k && p.second < pq.top().first) pq.pop();
            if(pq.size() < freq.size() - k) pq.push(make_pair(p.second , p.first));
        }

        set<int> not_contains;
        while(!pq.empty()){
            not_contains.insert(pq.top().second);
            pq.pop();
        }

        vector<int> res;
        for(const pair<int, int>& p: freq)
            if(!not_contains.count(p.first))
                res.push_back(p.first);
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    print_vec(Solution().topKFrequent(nums, 2));

    return 0;
}