/// Source : https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
/// Author : liuyubobobo
/// Time   : 2021-01-30

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {

        int n = candiesCount.size();
        vector<long long> presum(n + 1, 0ll);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + candiesCount[i];

        vector<bool> res(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            int type = queries[i][0], day = queries[i][1], cap = queries[i][2];

            if(day >= presum[type + 1]) res[i] = false;
            else if((long long)(day + 1) * cap <= presum[type]) res[i] = false;
            else res[i] = true;
        }
        return res;
    }
};


void print_vec(const vector<bool>& v){
    for(bool e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> candies1 = {7, 4, 5, 3, 8};
    vector<vector<int>> queries1 = {{0, 2, 2}, {4, 2, 4}, {2, 13, 1000000000}};
    print_vec(Solution().canEat(candies1, queries1));
    // 1 0 1

    vector<int> candies2 = {5,2,6,4,1};
    vector<vector<int>> queries2 = {{3, 1, 2}, {4, 10, 3}, {3, 10, 100}, {4, 100, 30}, {1, 3, 1}};
    print_vec(Solution().canEat(candies2, queries2));
    // 0 1 1 0 0

    return 0;
}
