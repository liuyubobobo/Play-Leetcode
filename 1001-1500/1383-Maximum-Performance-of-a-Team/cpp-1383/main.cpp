/// Source : https://leetcode.com/problems/maximum-performance-of-a-team/
/// Author : liuyubobobo
/// Time   : 2020-05-05

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Greedy + Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {

        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i ++) vec.push_back({speed[i], efficiency[i]});
        sort(vec.begin(), vec.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second > p2.second;
        });

        long long res = (long long)vec[0].first * vec[0].second;
        long long speedsum = vec[0].first;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(vec[0]);
        for(int i = 1; i < n; i ++){
            if(i < k){
                res = max(res, (long long)vec[i].second * (speedsum + vec[i].first));
                speedsum += vec[i].first;
                pq.push(vec[i]);
            }
            else{
                long long tres = (long long)vec[i].second * (speedsum - pq.top().first + vec[i].first);
                res = max(res, tres);
                if(pq.top().first < vec[i].first){
                    speedsum = speedsum - pq.top().first + vec[i].first;
                    pq.pop();
                    pq.push(vec[i]);
                }
            }
        }

        return res % MOD;
    }
};


int main() {

    vector<int> speed1 = {2,10,3,1,5,8};
    vector<int> efficiency1 = {5,4,3,9,7,2};
    cout << Solution().maxPerformance(6, speed1, efficiency1, 2) << endl;
    // 60

    vector<int> speed2 = {2,10,3,1,5,8};
    vector<int> efficiency2 = {5,4,3,9,7,2};
    cout << Solution().maxPerformance(6, speed2, efficiency2, 3) << endl;
    // 68

    vector<int> speed3 = {2,10,3,1,5,8};
    vector<int> efficiency3 = {5,4,3,9,7,2};
    cout << Solution().maxPerformance(6, speed3, efficiency3, 4) << endl;
    // 72

    return 0;
}
