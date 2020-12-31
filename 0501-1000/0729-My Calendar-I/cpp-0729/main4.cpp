/// Source : https://leetcode.com/problems/my-calendar-i/description/
/// Author : liuyubobobo
/// Time   : 2017-11-20

#include <iostream>
#include <set>

using namespace std;

/// Using Tree Set with logn book
/// Time Complexity: book: O(logn)
///                  total: O(nlogn)
/// Space Complexity: O(n)
class MyCalendar {

private:
    set<pair<int, int>> calendar;

public:
    MyCalendar() {
        calendar.clear();
    }

    bool book(int start, int end) {

        pair<int, int> newp = make_pair(start, end);

        set<pair<int, int>>::iterator iter = calendar.lower_bound(newp);
        if(iter != calendar.end() && overlapped(*iter, newp))
            return false;
        if(iter != calendar.begin()){
            advance(iter, -1);
            if(overlapped(*iter, newp))
                return false;
        }

        calendar.insert(newp);
        return true;
    }

private:
    // Another easy way to check whether pa and pb overlapped
    // pa.start < pb.end && pa.end > pb.start
    bool overlapped(const pair<int, int>&pa, const pair<int, int>& pb){
        return pa.first < pb.second && pa.second > pb.first;
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