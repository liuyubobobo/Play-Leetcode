/// Source : https://leetcode.com/problems/largest-rectangle-in-histogram/
/// Author : liuyubobobo
/// Time   : 2019-04-09

#include <iostream>
#include <vector>

using namespace std;


/// Divide and Conquer
/// Time Complexity: average: O(nlogn)
///                  worst: O(n^2)
/// Space Complexity: average: O(logn)
///                   worst: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        if(!n) return 0;

        return get_res(heights, 0, n - 1);
    }

private:
    int get_res(const vector<int>& heights, int l, int r){

        if(l > r) return 0;
        if(l == r) return heights[l];

        int minv = heights[l], min_index = l;
        for(int i = l + 1; i <= r; i ++)
            if(heights[i] < minv)
                minv = heights[i], min_index = i;

        return max(minv * (r - l + 1),
                   max(get_res(heights, l, min_index - 1), get_res(heights, min_index + 1, r)));
    }
};


int main() {

    return 0;
}