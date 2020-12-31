/// Source : https://leetcode.com/problems/ordinal-number-of-date/discuss/?currentPage=1&orderBy=hot&query=
/// Author : liuyubobobo
/// Time   : 2019-08-10

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(12)
/// Space Complexity: O(1)
class Solution {
public:
    int dayOfYear(string date) {

        vector<int> a = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> b = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int year = atoi(date.substr(0, 4).c_str());
        int month = atoi(date.substr(5, 2).c_str());
        int day = atoi(date.substr(8, 2).c_str());

        vector<int>& v = is_leap_year(year) ? b : a;

        int res = 0;
        for(int i = 0; i < month - 1; i ++) res += v[i];
        return res + day;
    }

private:
    bool is_leap_year(int year){
        return (year % 4 == 0 && year % 100) || (year % 400 == 0);
    }
};


int main() {

    cout << Solution().dayOfYear("2019-01-09") << endl;
    // 9

    cout << Solution().dayOfYear("2019-02-10") << endl;
    // 41

    cout << Solution().dayOfYear("2003-03-01") << endl;
    // 60

    cout << Solution().dayOfYear("2004-03-01") << endl;
    // 61

    return 0;
}