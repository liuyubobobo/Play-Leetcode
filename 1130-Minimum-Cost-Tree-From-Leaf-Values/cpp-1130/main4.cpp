/// Source : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
/// Author : liuyubobobo
/// Time   : 2019-08-22

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Greedy
/// Using sentel to make the logic more concise
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int mctFromLeafValues(vector<int>& arr) {

        arr.insert(arr.begin(), INT_MAX);
        arr.push_back(INT_MAX);

        stack<int> stack;
        int res = 0;
        for(int i = 0; i < arr.size(); i ++){
            while(!stack.empty() && arr[stack.top()] < arr[i]){
                int cur = stack.top();
                stack.pop();
                int minv = min(arr[stack.top()], arr[i]);
                if(minv != INT_MAX) res += arr[cur] * minv;
            }
            stack.push(i);
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