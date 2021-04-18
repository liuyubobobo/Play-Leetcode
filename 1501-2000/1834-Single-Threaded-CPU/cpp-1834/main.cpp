/// Source : https://leetcode.com/problems/single-threaded-cpu/
/// Author : liuyubobobo
/// Time   : 2021-04-17

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Sorting + Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        for(int i = 0; i < tasks.size(); i ++)
            tasks[i].push_back(i);

        sort(tasks.begin(), tasks.end(), [](const vector<int>& t1, const vector<int>& t2){
           if(t1[0] != t2[0]) return t1[0] < t2[0];
           if(t1[2] != t2[2]) return t1[2] < t2[2];
           return t1[1] < t2[1];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res;
        long long curt = 0;
        int index = 0;
        while(res.size() != tasks.size()){
            if(pq.empty()){
                curt = (long long)tasks[index][0];
            }
            else{
                int process_time = pq.top().first, id = pq.top().second;
                pq.pop();
                res.push_back(id);
                curt += (long long)process_time;
            }

            while(index < tasks.size() && tasks[index][0] <= curt)
                pq.push({tasks[index][1], tasks[index][2]}), index ++;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> task1 = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    print_vec(Solution().getOrder(task1));
    // 0 2 3 1

    vector<vector<int>> task2 = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};
    print_vec(Solution().getOrder(task2));
    // 4 3 2 0 1

    return 0;
}
