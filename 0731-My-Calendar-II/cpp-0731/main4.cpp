/// Source : https://leetcode.com/problems/my-calendar-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-27

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

/// Boundary Count
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class MyCalendarTwo {

private:
    map<int, int> boundary;

public:
    MyCalendarTwo() {

        boundary.clear();
    }

    bool book(int start, int end) {

        boundary[start] += 1;
        boundary[end] -= 1;

        int count = 0;
        for(const pair<int, int>& p: boundary){
            count += p.second;
            if(count > 2){
                boundary[start] -= 1;
                boundary[end] += 1;
                return false;
            }
        }

        return true;
    }

private:
    bool overlapped(const pair<int, int> p1, const pair<int, int> p2){
        return p1.first < p2.second && p1.second > p2.first;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    MyCalendarTwo calendar;
    printBool(calendar.book(10, 20)); // returns true
    printBool(calendar.book(50, 60)); // returns true
    printBool(calendar.book(10, 40)); // returns true
    printBool(calendar.book(5, 15)); // returns false
    printBool(calendar.book(5, 10)); // returns true
    printBool(calendar.book(25, 55)); // returns true

    cout << endl;

    // ---

    MyCalendarTwo calendar2;
    printBool(calendar2.book(26, 35)); // returns true
    printBool(calendar2.book(26, 32)); // returns true
    printBool(calendar2.book(25, 32)); // returns false
    printBool(calendar2.book(18, 26)); // returns true
    printBool(calendar2.book(40, 45)); // returns true
    printBool(calendar2.book(19, 26)); // returns true
    printBool(calendar2.book(48, 50)); // returns true
    printBool(calendar2.book(1, 6));   // returns true
    printBool(calendar2.book(46, 50)); // returns true
    printBool(calendar2.book(11, 18)); // returns true

    cout << endl;

    // ---

    MyCalendarTwo calendar3;
    printBool(calendar3.book(36, 41)); // returns true
    printBool(calendar3.book(28, 34)); // returns true
    printBool(calendar3.book(40, 46)); // returns true
    printBool(calendar3.book(10, 18)); // returns true
    printBool(calendar3.book(4, 11));  // returns true
    printBool(calendar3.book(25, 34)); // returns true
    printBool(calendar3.book(36, 44)); // returns false
    printBool(calendar3.book(32, 40)); // returns false
    printBool(calendar3.book(34, 39)); // returns true
    printBool(calendar3.book(40, 49)); // returns false

    return 0;
}