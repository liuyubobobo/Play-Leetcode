/// Source : https://leetcode.com/problems/max-value-of-equation/
/// Author : liuyubobobo
/// Time   : 2020-06-28

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, int>> pq;

        // 初始放入第一个点的信息
        pq.push({points[0][1] - points[0][0], points[0][0]});

        int res = INT_MIN;
        for(int i = 1; i < points.size(); i ++){
            // 将优先队列队头不符合条件的点扔掉
            while(!pq.empty() && points[i][0] - pq.top().second > k) pq.pop();

            // 使用优先队列队首元素信息更新解
            if(!pq.empty())
                res = max(res, points[i][1] + points[i][0] + pq.top().first);

            // 将当前点的信息放入优先队列
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return res;
    }
};


int main() {

    vector<vector<int>> points1 = {{1,3},{2,0},{5,10},{6,-10}};
    cout << Solution().findMaxValueOfEquation(points1, 1) << endl;
    // 4

    vector<vector<int>> points2 = {{0,0},{3,0},{9,2}};
    cout << Solution().findMaxValueOfEquation(points2, 3) << endl;
    // 3

    return 0;
}
