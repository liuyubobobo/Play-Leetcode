/// Source : https://leetcode.com/problems/maximum-average-pass-ratio/submissions/
/// Author : liuyubobobo
/// Time   : 2021-03-13

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(n + mlogn)
/// Space Complexity: O(n)
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < classes.size(); i ++)
            pq.push({(double)(classes[i][0] + 1) / (classes[i][1] + 1) - (double)classes[i][0] / classes[i][1], i});

        while(extraStudents){
            int i = pq.top().second;
            pq.pop();

            classes[i][0] ++;
            classes[i][1] ++;
            pq.push({(double)(classes[i][0] + 1) / (classes[i][1] + 1) - (double)classes[i][0] / classes[i][1], i});
            extraStudents --;
        }

        double sum = 0.0;
        for(const vector<int>& data: classes)
            sum += (double)data[0] / data[1];
        return sum / classes.size();
    }
};


int main() {

    vector<vector<int>> classes1 = {{1, 2}, {3, 5}, {2, 2}};
    cout << Solution().maxAverageRatio(classes1, 2) << endl;
    // 0.78333

    vector<vector<int>> classes2 = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
    cout << Solution().maxAverageRatio(classes2, 4) << endl;
    // 0.53485

    return 0;
}
