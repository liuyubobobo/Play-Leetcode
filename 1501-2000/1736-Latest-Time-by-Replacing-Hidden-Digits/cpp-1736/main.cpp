/// Source : https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/
/// Author : liuyubobobo
/// Time   : 2021-01-23

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(10^4)
/// Space Complexity: O(1)
class Solution {
public:
    string maximumTime(string time) {

        return dfs(time, 0);
    }

private:
    string dfs(string& time, int index){

        if(index == time.size()){
            return ok(time) ? time : "00:00";
        }

        if(time[index] != '?') return dfs(time, index + 1);

        string res = "00:00";
        for(char c = '0'; c <= '9'; c ++){
            time[index] = c;
            res = max(res, dfs(time, index + 1));
            time[index] = '?';
        }
        return res;
    }

    bool ok(const string& time){
        int h = atoi(time.substr(0, 2).c_str());
        int m = atoi(time.substr(3).c_str());
        return h >= 0 && h <= 23 && m >= 0 && m <= 59;
    }
};


int main() {

    string time1 = "2?:?0";
    cout << Solution().maximumTime(time1) << endl;
    // 23:50

    string time2 = "0?:3?";
    cout << Solution().maximumTime(time2) << endl;
    // 09:39

    string time3 = "1?:22";
    cout << Solution().maximumTime(time3) << endl;
    // 19:22

    return 0;
}
