/// Source : https://leetcode.com/problems/minimum-interval-to-include-each-query/
/// Author : liuyubobobo
/// Time   : 2021-05-03

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Offline Algorithm + Priority Queue
/// Time Complexity: O(nlogn + (n + q)logq)
/// Space Complexity: O(n + q)
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> qv;
        for(int i = 0; i < queries.size(); i ++)
            qv.push_back({queries[i], i});
        sort(qv.begin(), qv.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // len, end

        int ii = 0;
        vector<int> res(qv.size(), -1);
        for(const pair<int, int>& p: qv){
            int q = p.first, index = p.second;
            while(ii < intervals.size() && intervals[ii][0] <= q){
                pq.push({intervals[ii][1] - intervals[ii][0] + 1, intervals[ii][1]});
                ii ++;
            }

            while(!pq.empty() && pq.top().second < q) pq.pop();

            if(!pq.empty()) res[index] = pq.top().first;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> intervals1 = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
    vector<int> queries1 = {2, 3, 4, 5};
    print_vec(Solution().minInterval(intervals1, queries1));
    // 3 3 1 4

    vector<vector<int>> intervals2 = {{2, 3}, {2, 5}, {1, 8}, {20, 25}};
    vector<int> queries2 = {2, 19, 5, 22};
    print_vec(Solution().minInterval(intervals2, queries2));
    // 2,-1,4,6

    vector<vector<int>> intervals3 = {{9, 9}, {9, 10}};
    vector<int> queries3 = {9};
    print_vec(Solution().minInterval(intervals3, queries3));
    // 1

    vector<vector<int>> intervals4 = {{5, 10}, {7, 7}};
    vector<int> queries4 = {6, 6};
    print_vec(Solution().minInterval(intervals4, queries4));
    // 6 6

    return 0;
}
