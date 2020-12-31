/// Source : https://leetcode.com/problems/k-closest-points-to-origin/
/// Author : liuyubobobo
/// Time   : 2019-01-21

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Quick Sort based k-selection algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

        int n = points.size();
        selectionK(points, 0, n - 1, K - 1);
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }

private:
    void selectionK(vector<vector<int>>& points, int start, int end, int K){

        if(start >= end) return;

        int d = points[start][0] * points[start][0] + points[start][1] * points[start][1];
        int p = start; // arr[start + 1...p] < v
        for(int i = start + 1; i <= end; i ++)
            if(points[i][0] * points[i][0] + points[i][1] * points[i][1] <= d)
                swap(points[i], points[++p]);
        swap(points[start], points[p]);

        if(p == K) return;
        if(p > K) selectionK(points, start, p - 1, K);
        selectionK(points, p + 1, end, K);
    }
};


void print_vec(const vector<vector<int>>& vec){
    for(const vector<int>& e: vec)
        cout << "[" << e[0] << "," << e[1] << "] ";
    cout << endl;
}

int main() {

    vector<vector<int>> points1 = {
            {68,97},{34,-84},{60,100},{2,31},{-27,-38},{-73,-74},{-55,-39},{62,91},{62,92},{-57,-67}
    };
    int K1 = 5;
    print_vec(Solution().kClosest(points1, K1));
    // [[2,31],[-27,-38],[-55,-39],[-57,-67],[34,-84]]

    return 0;
}