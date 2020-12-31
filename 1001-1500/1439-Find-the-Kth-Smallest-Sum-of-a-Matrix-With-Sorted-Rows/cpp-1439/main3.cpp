/// Source : https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(log(maxnum - minnum) * k)
/// Space Complexity: O(R)
class Solution {

private:
    int R, C;

public:
    int kthSmallest(vector<vector<int>>& mat, int k) {

        R = mat.size(), C = mat[0].size();

        int minv = 0;
        for(int i = 0; i < R; i ++) minv += mat[i][0];

        if(C == 1) return minv;

        int maxv = 0;
        for(int i = 0; i < R; i ++) maxv += mat[i].back();

        int l = minv, r = maxv;
        while(l < r){
            int mid = (l + r) / 2;
            if(count(mat, mid) >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    int count(const vector<vector<int>>& mat, int x){
        return count(mat, 0, x);
    }

    int count(const vector<vector<int>>& mat, int start, int x){

        if(start == R) return 1;

        int sum = 0;

        int i, j;
        for(i = R - 1; i > start; i --) sum += mat[i][0];
        for(j = C - 1; j >= 0; j --) if(mat[start][j] <= x - sum) break;

        int res = 0;
        for(; j >= 0; j --) {
            res += count(mat, start + 1, x - mat[start][j]);
            if(res > 200) return res;
        }
        return res;
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
