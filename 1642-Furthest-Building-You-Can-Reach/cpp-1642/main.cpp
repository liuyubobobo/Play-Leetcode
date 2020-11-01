/// Source : https://leetcode.com/problems/furthest-building-you-can-reach/
/// Author : liuyubobobo
/// Time   : 2020-10-31

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/// Priority Queue + Greedy
/// Time Complexity: O(nlogk)
/// Space Complexity: O(k)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i < heights.size(); i ++)
            if(heights[i] > heights[i - 1]){
                int a = heights[i] - heights[i - 1];
                pq.push(a);
                if(pq.size() > ladders){
                    int x = pq.top(); pq.pop();
                    if(x > bricks) return i - 1;
                    bricks -= x;
                }
            }
        return heights.size() - 1;
    }
};


int main() {

    vector<int> heights1 = {4,2,7,6,9,14,12};
    cout << Solution().furthestBuilding(heights1, 5, 1) << endl;
    // 4

    vector<int> heights2 = {4,12,2,7,3,18,20,3,19};
    cout << Solution().furthestBuilding(heights2, 10, 2) << endl;
    // 7

    vector<int> heights3 = {14,3,19,3};
    cout << Solution().furthestBuilding(heights3, 17, 0) << endl;
    // 3

    return 0;
}
