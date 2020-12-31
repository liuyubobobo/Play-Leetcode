/// Source : https://leetcode.com/problems/largest-rectangle-in-histogram/
/// Author : liuyubobobo
/// Time   : 2020-05-13

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Monotone Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        if(!n) return 0;

        stack<int> stack;
        int res = 0;
        for(int i = 0; i < n; i ++){
            while(!stack.empty() && heights[i] < heights[stack.top()]){
                int x = stack.top();
                res = max(res, heights[x]);
                stack.pop();
                if(!stack.empty()) res = max(res, heights[x] * (i - 1 - (stack.top() + 1) + 1));
                else res = max(res, heights[x] * i);
            }
            stack.push(i);
        }

        if(!stack.empty()){
            int r = stack.top();
            while(!stack.empty()){
                int x = stack.top();
                stack.pop();
                res = max(res, heights[x]);

                if(!stack.empty()) res = max(res, heights[x] * (r - (stack.top() + 1) + 1));
                else res = max(res, heights[x] * n);
            }
        }
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
