/// Source : https://leetcode.com/problems/day-of-the-week/
/// Author : liuyubobobo
/// Time   : 2019-09-08

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(year + month + day)
/// Space Complexity: O(1)
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {

        int x = 0;
        for(int i = 1971; i < year; i ++)
            if(isLeapYear(i)) x += 366;
            else x += 365;

        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(isLeapYear(year)) months[1] = 29;
        for(int i = 1; i < month; i ++) x += months[i - 1];

        x += day;

        string res[7] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
        return res[x % 7];
    }

private:
    bool isLeapYear(int year){
        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    }
};


int main() {

    cout << Solution().dayOfTheWeek(31, 8, 2019) << endl;
    // Saturday

    return 0;
}