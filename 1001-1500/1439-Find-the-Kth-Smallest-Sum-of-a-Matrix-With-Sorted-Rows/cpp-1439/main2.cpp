/// Source : https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
/// Author : liuyubobobo
/// Time   : 2020-05-03

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Brute Force - Using Priority Queue to optimize
/// Keep first k elements int every row
/// Time Complexity: O(m * (n * k + n * k * logk))
/// Space Complexity: O(n * k)
class Solution {

public:
    int kthSmallest(vector<vector<int>>& mat, int k) {

        vector<int> res = {0};
        priority_queue<int> pq;
        for(const vector<int>& row: mat){
            for(int a: res) for(int b: row){
                pq.push(a + b);
                if(pq.size() > k) pq.pop();
            }
            res.clear();
            while (!pq.empty()) res.push_back(pq.top()), pq.pop();
        }
        return res[0];
    }
};


int main() {

    vector<vector<int>> mat1 = {{1, 3, 11}, {2, 4, 6}};
    cout << Solution().kthSmallest(mat1, 5) << endl;
    // 7

    vector<vector<int>> mat2 = {{1, 3, 11}, {2, 4, 6}};
    cout << Solution().kthSmallest(mat2, 9) << endl;
    // 17

    vector<vector<int>> mat3 = {{1, 10, 10}, {1, 4, 5}, {2, 3, 6}};
    cout << Solution().kthSmallest(mat3, 7) << endl;
    // 9

    vector<vector<int>> mat4 = {{1, 1, 10}, {2, 2, 9}};
    cout << Solution().kthSmallest(mat4, 7) << endl;
    // 12

    return 0;
}
