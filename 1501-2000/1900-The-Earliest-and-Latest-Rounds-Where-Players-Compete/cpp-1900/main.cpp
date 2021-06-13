/// Source : https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^3*2^n)
/// Space Complexity: O(n^3*2^n)
class Solution {

public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {

        vector<vector<vector<int>>> dp1(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        int minv = dfs(firstPlayer - 1, secondPlayer - firstPlayer - 1, n - secondPlayer, dp1, "min");

        vector<vector<vector<int>>> dp2(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        int maxv = dfs(firstPlayer - 1, secondPlayer - firstPlayer - 1, n - secondPlayer, dp2, "max");

        return {minv + 1, maxv + 1};
    }

private:
    int dfs(int pre1, int pre2, int post, vector<vector<vector<int>>>& dp, const string& op){

        if(dp[pre1][pre2][post] != -1) return dp[pre1][pre2][post];

        int n = pre1 + 1 + pre2 + 1 + post;
        int player1 = pre1;
        int player2 = pre1 + 1 + pre2;

        set<vector<int>> result_set;
        vector<bool> result(n, false);
        if(n % 2 == 1) result[n / 2] = true;
        bool ok = play(0, player1, player2, result, result_set);

        if(ok) return dp[pre1][pre2][post] = 0;

        int res = (op == "min") ? INT_MAX : INT_MIN;
        for(const vector<int>& state: result_set)
            if(op == "min")
                res = min(res, 1 + dfs(state[0], state[1], state[2], dp, op));
            else
                res = max(res, 1 + dfs(state[0], state[1], state[2], dp, op));

        return dp[pre1][pre2][post] = res;
    }

    bool play(int index, int player1, int player2,
              vector<bool>& result, set<vector<int>>& result_set){

        if(index >= (result.size() / 2)){
            int a = 0, b = 0, c = 0;
            for(int i = 0; i < result.size(); i ++)
                if(result[i]){
                    if(i < player1) a ++;
                    else if(i > player1 && i < player2) b ++;
                    else if(i > player2) c ++;
                }
            result_set.insert({a, b, c});
//            if(a + b + c + 2 != (result.size() + 1) / 2){
//                cout << "player1 : " << player1 << " palyer2 : " << player2 << endl;
//                for(int e: result) cout << e << " "; cout << endl;
//                cout << a << " " << b << " " << c << endl;
//                assert(false);
//            }
            return false;
        }

        int x = index, y = result.size() - 1 - index;
        if(x == player1 && y == player2) return true;

        if(x == player1 || x == player2){
            result[x] = true;
            result[y] = false;
            if(play(index + 1, player1, player2, result, result_set))
                return true;
            return false;
        }

        if(y == player1 || y == player2){
            result[x] = false;
            result[y] = true;
            if(play(index + 1, player1, player2, result, result_set))
                return true;
            return false;
        }

        result[x] = true;
        result[y] = false;
        if(play( index + 1, player1, player2, result, result_set))
            return true;

        result[x] = false;
        result[y] = true;
        if(play( index + 1, player1, player2, result, result_set))
            return true;

        return false;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    print_vec(Solution().earliestAndLatest(11, 2, 4));
    // {3, 4}

    print_vec(Solution().earliestAndLatest(5, 1, 5));
    // {1, 1}

    return 0;
}
