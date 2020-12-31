/// Source : https://leetcode.com/problems/filling-bookcase-shelves/
/// Author : liuyubobobo
/// Time   : 2019-07-07

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {

        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i ++){
            for(int j = i, total_thick = 0, cur_height = 0; j >= 0 && total_thick + books[j][0] <= shelf_width; j --){
                total_thick += books[j][0];
                cur_height = max(cur_height, books[j][1]);
                dp[i + 1] = min(dp[i + 1], cur_height + dp[j]);
            }
        }
        return dp.back();
    }
};


int main() {

    vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    cout << Solution().minHeightShelves(books, 4) << endl;
    // 6

    return 0;
}