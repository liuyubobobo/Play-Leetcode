/// Source : https://leetcode.com/problems/number-of-days-between-two-dates/
/// Author : liuyubobobo
/// Time   : 2020-02-22

#include <iostream>
#include <vector>

using namespace std;


/// Date Counting
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {

        if(date1 > date2) swap(date1, date2);
        int a = getDays(atoi(date1.substr(0, 4).c_str()),
                        atoi(date1.substr(5, 2).c_str()),
                        atoi(date1.substr(8, 2).c_str()));
        int b = getDays(atoi(date2.substr(0, 4).c_str()),
                        atoi(date2.substr(5, 2).c_str()),
                        atoi(date2.substr(8, 2).c_str()));
        return b - a;
    }

private:
    int getDays(int Y, int M, int D){
        int res = 0;
        for(int i = 1970; i < Y; i ++)
            res += isLeapYear(i) ? 366 : 365;

        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 0; i < M - 1; i ++){
            res += months[i];
            if(i == 1) res += isLeapYear(Y);
        }

        return res + D;
    }

    bool isLeapYear(int Y){
        return (Y % 4 == 0 && Y % 100 != 0 ) || Y % 400 == 0;
    }
};


int main() {

    return 0;
}
