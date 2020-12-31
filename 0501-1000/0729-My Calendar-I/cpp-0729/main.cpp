/// Source : https://leetcode.com/problems/my-calendar-i/description/
/// Author : liuyubobobo
/// Time   : 2017-11-20
#include <iostream>
#include <vector>

using namespace std;

/// Brute Force
/// Time Complexity: book: O(n)
///                  total: O(n^2)
/// Space Complexity: O(n)
class MyCalendar {

private:
    vector<pair<int, int>> calendar;

public:
    MyCalendar() {
        calendar.clear();
    }

    bool book(int start, int end) {

        pair<int, int> newp = make_pair(start, end);
        for(pair<int, int> p: calendar)
            if(overlapped(p, newp))
                return false;

        calendar.push_back(newp);
        return true;
    }

private:
    // To check whether pa and pb overlapped
    // we check every points in each pair are within another pair
    bool overlapped(const pair<int, int>&pa, const pair<int, int>& pb){
        return ((pa.first >= pb.first) && (pa.first < pb.second)) ||
               ((pa.second > pb.first) && (pa.second <= pb.second)) ||
               ((pb.first >= pa.first) && (pb.first < pa.second)) ||
               ((pb.second > pa.first) && (pb.second <= pa.second));
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False" ) << endl;
}

int main() {

    MyCalendar calendar;
    printBool(calendar.book(10, 20)); // returns true
    printBool(calendar.book(15, 25)); // returns false
    printBool(calendar.book(20, 30)); // returns true

    return 0;
}