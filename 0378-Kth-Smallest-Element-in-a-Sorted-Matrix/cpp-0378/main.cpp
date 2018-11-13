/// Source : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
/// Author : liuyubobobo
/// Time   : 2018-11-13

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(m * n * logk)
/// Space Complexity: O(k)
class Solution {

private:
    class Element{
    public:
        int x, y, val;
        Element(int x, int y, int val): x(x), y(y), val(val){}
    };

    class CompareElement{
    public:
        bool operator()(const Element& e1, const Element& e2){
            return e1.val > e2.val;
        }
    };

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int m = matrix.size(), n = matrix[0].size();
        priority_queue<Element, vector<Element>, CompareElement> pq;
        vector<vector<int>> visited(m, vector<int>(n, false));

        pq.push(Element(0, 0, matrix[0][0]));
        visited[0][0] = true;

        int cur;
        for(int i = 0; i < k; i ++){
            int x = pq.top().x, y = pq.top().y;
            cur = pq.top().val;
            pq.pop();

            if(x + 1 < m && !visited[x + 1][y]){
                pq.push(Element(x + 1, y, matrix[x + 1][y]));
                visited[x + 1][y] = true;
            }

            if(y + 1 < n && !visited[x][y + 1]){
                pq.push(Element(x, y + 1, matrix[x][y + 1]));
                visited[x][y + 1] = true;
            }
        }

        return cur;
    }
};


int main() {

    vector<vector<int>> matrix1 = {{-5}};
    cout << Solution().kthSmallest(matrix1, 1) << endl;
    // -5

    vector<vector<int>> matrix2 = {
            {1,  5,  9},
            {10, 11, 13},
            {12, 13, 15}
    };
    cout << Solution().kthSmallest(matrix2, 8) << endl;
    // 13

    vector<vector<int>> matrix3 = {
            {1,  3,  5},
            {6,  7,  12},
            {11, 14, 14}
    };
    cout << Solution().kthSmallest(matrix3, 3) << endl;
    // 5

    vector<vector<int>> matrix4 = {
            {1,  3,  5},
            {6,  7,  12},
            {11, 14, 14}
    };
    cout << Solution().kthSmallest(matrix4, 6) << endl;
    // 11

    return 0;
}