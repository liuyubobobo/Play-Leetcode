/// Source : https://leetcode-cn.com/problems/volume-of-histogram-lcci/
/// Author : liuyubobobo
/// Time   : 2021-04-02

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        if(!n) return 0;

        vector<int> leftmax(n, height[0]), rightmax(n, height.back());
        for(int i = 1; i < n; i ++)
            leftmax[i] = max(leftmax[i - 1], height[i]);
        for(int i = n - 2; i >= 0; i --)
            rightmax[i] = max(rightmax[i + 1], height[i]);

        int res = 0;
        for(int i = 0; i < height.size(); i ++){
            int bound = min(leftmax[i], rightmax[i]);
            if(bound > height[i]) res += bound - height[i];
        }
        return res;
    }
};


int main() {

    return 0;
}
