/// Source : https://leetcode.com/problems/strobogrammatic-number-ii/
/// Author : liuyubobobo
/// Time   : 2021-03-08

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Backtracking
/// Time Complexity: O((n / 2) ^ 5)
/// Space Complexity: O(n)
class Solution {

private:
    const map<char, char> table = {
            {'0', '0'},
            {'1', '1'},
            // {'2', '2'},
            // {'5', '5'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
    };

public:
    vector<string> findStrobogrammatic(int n) {

        vector<string> res;
        string cur(n, ' ');
        dfs(0, n, cur, res);
        return res;
    }

private:
    void dfs(int index, int n, string& cur, vector<string>& res){

        if(index > (n - 1) / 2){
            res.push_back(cur);
            return;
        }

        for(const pair<char, char>& p: table){

            if(index == 0 && p.first == '0' && n > 1) continue;

            if(n % 2 && index == n / 2 && (p.first == '6' || p.first == '9')) continue;

            cur[index] = p.first;
            cur[n - index - 1] = p.second;
            dfs(index + 1, n, cur, res);
        }
    }
};

int main() {

    return 0;
}
