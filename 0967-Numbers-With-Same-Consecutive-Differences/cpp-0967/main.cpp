/// Source : https://leetcode.com/problems/numbers-with-same-consecutive-differences/
/// Author : liuyubobobo
/// Time   : 2019-03-17

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(2^N)
/// Space Complexity: O(N)
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {

        vector<int> num(N, -1);
        vector<int> res;

        for(int i = 0 + (N != 1); i <= 9; i ++)
            dfs(num, 0, i, K, res);
        return res;
    }

private:
    void dfs(vector<int>& num, int pos, int digit, int K, vector<int>& res){

        num[pos] = digit;
        if(pos == num.size() - 1){
            res.push_back(get_num(num));
            return;
        }

        if(digit - K >= 0) dfs(num, pos + 1, digit - K, K, res);
        if(digit + K <= 9 && K) dfs(num, pos + 1, digit + K, K, res);
    }

    int get_num(const vector<int>& num){
        int ret = 0;
        for(int e: num) ret = ret * 10 + e;
        return ret;
    }
};


int main() {

    return 0;
}