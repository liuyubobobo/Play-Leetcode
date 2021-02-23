/// Source : https://leetcode.com/problems/search-a-2d-matrix-ii/
/// Author : liuyubobobo
/// Time   : 2021-02-23

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(min(R, C) * log(min(R, C)))
/// Space Complexity: O(1)
class Solution {

private:
    int R, C;

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        R = matrix.size();
        if(R == 0) return false;

        C = matrix[0].size();
        if(C == 0) return false;

        for(int i = 0; i < min(R, C); i ++){
            if(binary_search_h(matrix, i, target)) return true;
            if(binary_search_v(matrix, i, target)) return true;
        }
        return false;
    }

private:
    bool binary_search_h(vector<vector<int>>& matrix, int start, int target){
        vector<int>::iterator iter = lower_bound(matrix[start].begin() + start, matrix[start].end(), target);
        return iter != matrix[start].end() && *iter == target;
    }

    bool binary_search_v(vector<vector<int>>& matrix, int start, int target){

        int l = start, r = R - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(matrix[mid][start] == target) return true;
            else if(matrix[mid][start] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};


int main() {

    vector<vector<int>> matrix1 ={
            {1,4,7,11,15},
            {2,5,8,12,19},
            {3,6,9,16,22},
            {10,13,14,17,24},
            {18,21,23,26,30}
    };
    cout << Solution().searchMatrix(matrix1, 20) << endl;
    // 0

    return 0;
}
