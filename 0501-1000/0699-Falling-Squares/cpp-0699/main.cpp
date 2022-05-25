/// Source : https://leetcode.com/contest/leetcode-weekly-contest-54/problems/falling-squares/
/// Author : liuyubobobo
/// Time   : 2017-10-21
/// Updated: 2022-05-25

#include <iostream>
#include <vector>
using namespace std;


/// Using heights to record all the falling squares
/// Time Complexity: O(len(position)^2)
/// Space Complexity: O(len(position))
class Solution {

public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {

        int n = positions.size();
        vector<int> heights(n, 0);
        for(int i = 0 ; i < positions.size() ; i ++){

            heights[i] = positions[i][1];
            for(int j = 0 ; j < i ; j ++)
                if(intersection(positions[j], positions[i]))
                    heights[i] = max(heights[i], heights[j] + positions[i][1]);
        }

        vector<int> res(n, 0);
        res[0] = heights[0];
        for(int i = 1 ; i < n ; i ++)
            res[i] = max(heights[i], res[i-1]);

        return res;
    }

private:
    bool intersection(const vector<int>& a, const vector<int>& b){
        int l1 = a[0];
        int r1 = a[0] + a[1] - 1;
        int l2 = b[0];
        int r2 = b[0] + b[1] - 1;

        if(l1 > r2 || l2 > r1)
            return false;

        return true;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << ' '; cout << '\n';
}

int main() {

    vector<vector<int>> va = {{1, 2}, {2, 3}, {6, 1}};
    vector<int> res1 = Solution().fallingSquares(va);
    print_vec(res1);

    vector<vector<int>> vb = {{100, 100}, {200, 100}};
    vector<int> res2 = Solution().fallingSquares(vb);
    print_vec(res2);

    return 0;
}