/// Source : https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
/// Author : liuyubobobo
/// Time   : 2021-02-12

#include <iostream>
#include <vector>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();
        vector<int> visited(n + 1, 0);
        for(int e: nums) visited[e] ++;

        vector<int> res;
        for(int e = 1; e <= n; e ++) if(!visited[e]) res.push_back(e);
        return res;
    }
};


int main() {

    return 0;
}
