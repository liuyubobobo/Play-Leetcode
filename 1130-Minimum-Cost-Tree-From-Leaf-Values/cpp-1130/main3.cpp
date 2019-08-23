/// Source : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
/// Author : liuyubobobo
/// Time   : 2019-08-22

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int mctFromLeafValues(vector<int>& arr) {

        int n = arr.size();
        if(n == 1) return 0;

        stack<int> stack;
        stack.push(0);
        int res = 0;
        for(int i = 1; i < n; i ++){
            while(!stack.empty() && arr[stack.top()] < arr[i]){
                int cur = stack.top();
                stack.pop();
                if(stack.empty())
                    res += arr[cur] * arr[i];
                else
                    res += arr[cur] * min(arr[stack.top()], arr[i]);
            }
            stack.push(i);
        }

        while(stack.size() >= 2){
            int x = arr[stack.top()];
            stack.pop();
            res += x * arr[stack.top()];
        }
        return res;
    }
};


int main() {

    vector<int> vec1 = {6, 2, 4};
    cout << Solution().mctFromLeafValues(vec1) << endl;
    // 32

    vector<int> vec2 = {7, 12, 8, 10};
    cout << Solution().mctFromLeafValues(vec2) << endl;
    // 284

    vector<int> vec3 = {6, 15, 5, 2};
    cout << Solution().mctFromLeafValues(vec3) << endl;
    // 175

    vector<int> vec4 = {15, 13, 5, 3, 15};
    cout << Solution().mctFromLeafValues(vec4) << endl;
    // 500

    vector<int> vec5 = {6, 9, 6, 15, 15};
    cout << Solution().mctFromLeafValues(vec5) << endl;
    // 468

    return 0;
}