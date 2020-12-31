/// Source : https://leetcode.com/problems/minimum-time-to-build-blocks/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Huffman's Algorithm
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

public:
    int minBuildTime(vector<int>& blocks, int split) {

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int e: blocks) pq.push(e);
        while(pq.size() >= 2){
            int a = pq.top();pq.pop();
            int b = pq.top(); pq.pop();
            pq.push(b + split);
        }
        return pq.top();
    }
};


int main() {

    vector<int> blocks1 = {1};
    cout << Solution().minBuildTime(blocks1, 1) << endl;
    // 1

    vector<int> blocks2 = {1, 2};
    cout << Solution().minBuildTime(blocks2, 5) << endl;
    // 7

    vector<int> blocks3 = {1, 2, 3};
    cout << Solution().minBuildTime(blocks3, 1) << endl;
    // 4

    vector<int> blocks4 = {94961,39414,41263,7809,41473};
    cout << Solution().minBuildTime(blocks4, 90) << endl;
    // 95051

    return 0;
}