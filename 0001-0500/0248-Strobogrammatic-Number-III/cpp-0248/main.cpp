/// Source : https://leetcode.com/problems/strobogrammatic-number-iii/
/// Author : liuyubobobo
/// Time   : 2021-03-08

#include <iostream>
#include <map>

using namespace std;


/// Backtracking
/// Time Complexity: O(|high| * O((|high| / 2) ^ 5))
/// Space Complexity: O(|high|)
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
    int strobogrammaticInRange(string low, string high) {

        int res = 0;
        for(int len = low.size(); len <= high.size(); len ++){
            string cur(len, ' ');
            res += dfs(0, len, to_long_long(low), to_long_long(high), cur);
        }
        return res;
    }

private:
    int dfs(int index, int n, long long low, long long high, string& cur){

        if(index > (n - 1) / 2){
            long long num = to_long_long(cur);
            return low <= num && num <= high;
        }

        int res = 0;
        for(const pair<char, char>& p: table){

            if(index == 0 && p.first == '0' && n > 1) continue;

            if(n % 2 && index == n / 2 && (p.first == '6' || p.first == '9')) continue;

            cur[index] = p.first;
            cur[n - index - 1] = p.second;
            res += dfs(index + 1, n, low, high, cur);
        }
        return res;
    }

    long long to_long_long(const string& s){
        return atoll(s.c_str());
    }
};


int main() {

    return 0;
}
