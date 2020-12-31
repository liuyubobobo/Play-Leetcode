/// Source : https://leetcode.com/problems/daily-temperatures/description/
/// Author : liuyubobobo
/// Time   : 2018-08-28

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> res(temperatures.size(), 0);
        stack<int> stack;
        for(int i = temperatures.size() - 1; i >= 0 ; i --){
            while(!stack.empty() && temperatures[stack.top()] <= temperatures[i])
                stack.pop();

            if(!stack.empty())
                res[i] = stack.top() - i;
            stack.push(i);
        }

        return res;
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> vec = {73, 74, 75, 71, 69, 72, 76, 73};
    printVec(Solution().dailyTemperatures(vec));
    // 1 1 4 2 1 1 0 0

    return 0;
}