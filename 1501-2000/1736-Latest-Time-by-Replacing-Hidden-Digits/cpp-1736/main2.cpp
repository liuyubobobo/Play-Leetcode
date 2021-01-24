/// Source : https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/
/// Author : liuyubobobo
/// Time   : 2021-01-23

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    string maximumTime(string time) {

        if(time[0] == '?'){
            if(time[1] == '?' || time[1] <= '3') time[0] = '2';
            else time[0] = '1';
        }

        if(time[1] == '?'){
            time[1] = time[0] == '2' ? '3' : '9';
        }

        if(time[3] == '?') time[3] = '5';
        if(time[4] == '?') time[4] = '9';

        return time;
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
