/// Source : https://leetcode.com/problems/largest-rectangle-in-histogram/
/// Author : liuyubobobo
/// Time   : 2020-05-20

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// A very cool idea, using a dp-like thoughts
/// See here for details: https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28902/5ms-O(n)-Java-solution-explained-(beats-96)
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        if(!n) return 0;

        heights.insert(heights.begin(), INT_MAX);
        heights.push_back(INT_MAX);

        vector<int> left(n + 2), right(n + 2);
        left[0] = 0;
        for(int i = 1; i <= n; i ++){
            int p = i - 1;
            while(p > 0 && heights[i] <= heights[p])
                p = left[p];
            left[i] = p;
        }
//        for(int e: left) cout << e << " "; cout << endl;

        right[n + 1] = n + 1;
        for(int i = n; i >= 1; i --){
            int p = i + 1;
            while(p < n + 1 && heights[i] <= heights[p])
                p = right[p];
            right[i] = p;
        }
//        for(int e: right) cout << e << " "; cout << endl;

        int res = 0;
        for(int i = 1; i <= n; i ++)
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        return res;
    }
};


int main() {

    vector<int> heights1 = {2,1,5,6,2,3};
    cout << Solution().largestRectangleArea(heights1) << endl;
    // 10

    vector<int> heights2 = {2,1,2};
    cout << Solution().largestRectangleArea(heights2) << endl;
    // 3

    vector<int> heights3 = {0, 9};
    cout << Solution().largestRectangleArea(heights3) << endl;
    // 9

    vector<int> heights4 = {5, 4, 1, 2};
    cout << Solution().largestRectangleArea(heights4) << endl;
    // 8

    vector<int> heights5 = {1, 2, 3, 4, 5};
    cout << Solution().largestRectangleArea(heights5) << endl;
    // 9

    vector<int> heights6 = {4, 2, 0, 3, 2, 5};
    cout << Solution().largestRectangleArea(heights6) << endl;
    // 6

    return 0;
}
