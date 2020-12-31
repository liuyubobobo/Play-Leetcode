/// Source : https://leetcode.com/problems/my-calendar-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-27

#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

/// Boundary Count
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class MyCalendarThree {

private:
    map<int, int> boundary;

public:
    MyCalendarThree() {

        boundary.clear();
    }

    int book(int start, int end) {

        boundary[start] += 1;
        boundary[end] -= 1;

        int res = 0;
        int count = 0;
        for(const pair<int, int>& p: boundary){
            count += p.second;
            res = max(res, count);
        }

        return res;
    }
};


int main() {

    MyCalendarThree calendar;
    cout << calendar.book(10, 20) << endl; // 1
    cout << calendar.book(50, 60) << endl; // 1
    cout << calendar.book(10, 40) << endl; // 2
    cout << calendar.book(5, 15)  << endl; // 3
    cout << calendar.book(5, 10)  << endl; // 3
    cout << calendar.book(25, 55) << endl; // 3

    cout << endl;

    return 0;
}