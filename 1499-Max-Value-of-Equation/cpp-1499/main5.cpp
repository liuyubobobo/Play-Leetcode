/// Source : https://leetcode.com/problems/max-value-of-equation/
/// Author : liuyubobobo
/// Time   : 2020-06-28

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


/// Using Mono Queue
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        deque<pair<int, int>> dq;

        // 初始放入第一个点的信息
        dq.push_front({points[0][1] - points[0][0], points[0][0]});

        int res = INT_MIN;
        for(int i = 1; i < points.size(); i ++){

            // 对队列首不符合约束的点删除
            while(!dq.empty() && points[i][0] - dq.front().second > k)
                dq.pop_front();

            // 根据队首最大元素信息更新解
            if(!dq.empty())
                res = max(res, points[i][1] + points[i][0] + dq.front().first);

            // 把队列尾的比当前 y - x 还小的元素删除
            while(!dq.empty() && dq.back().first <= points[i][1] - points[i][0])
                dq.pop_back();

            // 将当前点的信息加入队列
            dq.push_back({points[i][1] - points[i][0], points[i][0]});
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
