/// Source : https://leetcode.com/problems/largest-rectangle-in-histogram/
/// Author : liuyubobobo
/// Time   : 2019-04-10

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int largestRectangleArea(vector<int>& heights) {

//        int n = heights.size();
//        if(!n) return 0;
//
//        stack<int> stack;
//        int res = 0;
//        for(int i = 0; i < n; i ++){
//
//            if(stack.empty() || heights[i] >= heights[stack.top()])
//                stack.push(i);
//            else{
//                while(!stack.empty() && heights[stack.top()] > heights[i]){
//                    res = max(res, )
//                }
//            }
//        }
    }
};


int main() {

    int a[3] = {1, 2, 3};
    cout << a[100] << endl;

    return 0;
}