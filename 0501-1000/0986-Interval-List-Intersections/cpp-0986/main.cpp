/// Source : https://leetcode.com/problems/interval-list-intersections/
/// Author : liuyubobobo
/// Time   : 2019-02-04
/// Updated: 2021-07-17

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(m + n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {

        vector<vector<int>> res;

        int i = 0, j = 0;
        while(i < A.size() && j < B.size()){

            int l = max(A[i][0], B[j][0]);
            int h = min(A[i][1], B[j][1]);
            if(l <= h)
                res.push_back({l, h});

            if(A[i][1] <= B[j][1])
                i ++;
            else
                j ++;
        }
        return res;
    }
};


void print_vec(const vector<vector<int>>& vec){

    for(const vector<int>& v: vec)
        cout << "(" << v[0] << "," << v[1] << ") ";
    cout << endl;
}

int main() {

    vector<vector<int>> A1 = {{0,2}, {5,10}, {13,23}, {24,25}};
    vector<vector<int>> B1 = {{1,5}, {8,12}, {15,24}, {25,26}};
    print_vec(Solution().intervalIntersection(A1, B1));
    // [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

    vector<vector<int>> A2 = {{5,10}};
    vector<vector<int>> B2 = {{5,10}};
    print_vec(Solution().intervalIntersection(A2, B2));
    // [[5, 10]]

    vector<vector<int>> A3 = {{3,5}, {9, 20}};
    vector<vector<int>> B3 = {{4,5}, {7, 10}, {11, 12}, {14, 15}, {16, 20}};
    print_vec(Solution().intervalIntersection(A3, B3));
    // [[4,5],[9,10],[11,12],[14,15],[16,20]]

    return 0;
}