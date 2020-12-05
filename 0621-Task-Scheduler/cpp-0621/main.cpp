/// Source : https://leetcode.com/problems/task-scheduler/
/// Author : liuyubobobo
/// Time   : 2020-12-05

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


/// Simulation with Priority Queue
/// Time Complexity: O(n * |task| * log|task|)
/// Space Coomplexity: O(|task|)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;
        for(char task: tasks) freq[task] ++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> frozen_pq; // last, task
        priority_queue<pair<int, int>> pq; // left, task

        for(const pair<int, int>& p: freq) pq.push({p.second, p.first});

        int t = 0;
        while(!pq.empty() || !frozen_pq.empty()){

            if(!pq.empty()){
                int task = pq.top().second;
                pq.pop();
                freq[task] --;
                if(freq[task]) frozen_pq.push({t, task});
                else freq.erase(task);
            }

            t ++;

            while(!frozen_pq.empty() && t - frozen_pq.top().first - 1 == n){
                int task = frozen_pq.top().second;
                pq.push({freq[task], task});
                frozen_pq.pop();
            }
        }
        return t;
    }
};


int main() {

    vector<char> v1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << Solution().leastInterval(v1, 2) << endl;
    // 8

    vector<char> v2 = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << Solution().leastInterval(v2, 0) << endl;
    // 6

    vector<char> v3 = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << Solution().leastInterval(v3, 2) << endl;
    // 16

    return 0;
}
