/// Source : https://leetcode.com/problems/trapping-rain-water/description/
/// Author : liuyubobobo
/// Time   : 2018-09-16

#include <iostream>
#include <vector>

using namespace std;


/// Using Stack
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() <= 2)
            return 0;

        vector<int> stack;
        int res = 0;
        for(int i = 0; i < height.size(); i ++){
            while(!stack.empty() && height[i] > height[stack.back()]){
                int cur = stack.back();
                stack.pop_back();
                if(stack.empty())
                    break;

                int dis = i - stack.back() - 1;
                int h = min(height[stack.back()], height[i]) - height[cur];
                res += h * dis;
            }
            stack.push_back(i);
        }
        return res;
    }
};


int main() {

    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(height1) << endl;
    // 6

    vector<int> height2 = {4,2,3};
    cout << Solution().trap(height2) << endl;
    // 1

    vector<int> height3 = {4, 2, 0, 3, 2, 5};
    cout << Solution().trap(height3) << endl;
    // 9

    return 0;
}