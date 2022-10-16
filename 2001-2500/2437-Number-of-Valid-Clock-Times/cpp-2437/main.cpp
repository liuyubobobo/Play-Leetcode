/// Source : https://leetcode.com/problems/number-of-valid-clock-times/
/// Author : liuyubobobo
/// Time   : 2022-10-15

#include <iostream>

using namespace std;


/// Backtrack
/// Time Complexity: O(10^4)
/// Space Complexity: O(1)
class Solution {
public:
    int countTime(string time) {

        return dfs(time, 0);
    }

private:
    int dfs(string& time, int index){

        if(index == 5){
            return is_valid_time(time);
        }

        if(time[index] != '?') return dfs(time, index + 1);

        int res = 0;
        for(char c = '0'; c <= '9'; c ++){
            time[index] = c;
            res += dfs(time, index + 1);
            time[index] = '?';
        }
        return res;
    }

    bool is_valid_time(const string& time){

        int h = atoi(time.substr(0, 2).c_str());
        int m = atoi(time.substr(3).c_str());
        return 0 <= h && h <= 23 && 0 <= m && m <= 59;
    }
};


int main() {

    cout << Solution().countTime("0?:0?") << '\n';
    // 100

    return 0;
}
