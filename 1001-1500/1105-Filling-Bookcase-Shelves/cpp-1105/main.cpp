/// Source : https://leetcode.com/problems/filling-bookcase-shelves/
/// Author : liuyubobobo
/// Time   : 2019-06-30

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    int n;

public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {

        n = books.size();
        vector<int> dp(n, -1);
        return dfs(books, 0, shelf_width, dp);
    }

private:
    int dfs(const vector<vector<int>>& books, int index, int shelf_width,
            vector<int>& dp){

        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];

        int res = INT_MAX, cur_height = 1;
        for(int i = index, total_thick = 0;
            i < n && total_thick + books[i][0] <= shelf_width; i ++){
            total_thick += books[i][0];
            cur_height = max(cur_height, books[i][1]);
            res = min(res, cur_height + dfs(books, i + 1, shelf_width, dp));
        }
        return dp[index] = res;
    }
};


int main() {

    vector<vector<int>> books = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    cout << Solution().minHeightShelves(books, 4) << endl;
    // 6

    return 0;
}