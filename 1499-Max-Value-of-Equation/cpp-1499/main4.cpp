/// Source : https://leetcode.com/problems/max-value-of-equation/
/// Author : liuyubobobo
/// Time   : 2020-06-28

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using BST 2
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        set<pair<int, int>> tree;

        // 初始放入第一个点的信息
        tree.insert({points[0][1] - points[0][0], points[0][0]});

        int res = INT_MIN;
        for(int i = 1; i < points.size(); i ++){

            // 取出红黑树中的最大 y - x 值，如果不满足约束，则删除
            while(!tree.empty() && points[i][0] - tree.rbegin()->second > k)
                tree.erase(--tree.end());

            // 使用红黑树最大元素信息更新解
            if(!tree.empty())
                res = max(res, points[i][1] + points[i][0] + tree.rbegin()->first);

            // 将当前点的信息放入红黑树
            tree.insert({points[i][1] - points[i][0], points[i][0]});
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
