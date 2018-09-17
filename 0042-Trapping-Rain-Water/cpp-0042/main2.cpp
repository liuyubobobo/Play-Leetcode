/// Source : https://leetcode.com/problems/trapping-rain-water/description/
/// Author : liuyubobobo
/// Time   : 2018-09-16

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size() <= 2)
            return 0;

        vector<int> rdp(height.size(), -1);
        getR(0, height, rdp);

        vector<int> ldp(height.size(), -1);
        getL(height.size() - 1, height, ldp);

        int res = 0;
        for(int i = 0; i < height.size(); i ++)
            res += min(ldp[i], rdp[i]) - height[i];
        return res;
    }

private:
    int getR(int index, const vector<int>& height, vector<int>& rdp){

        if(index == height.size() - 1)
            return rdp[index] = height[index];

        return rdp[index] = max(height[index], getR(index + 1, height, rdp));
    }

    int getL(int index, const vector<int>& height, vector<int>& ldp){

        if(index == 0)
            return ldp[index] = height[index];

        return ldp[index] = max(height[index], getL(index - 1, height, ldp));
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