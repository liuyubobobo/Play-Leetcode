/// Source : https://leetcode.com/problems/seat-reservation-manager/
/// Author : liuyubobobo
/// Time   : 2021-05-01

#include <iostream>
#include <set>

using namespace std;


/// Using TreeSet
/// Time Complexity: init: O(nlogn)
///                  reserve and unreserve: O(logn)
/// Space Complexity: O(n)
class SeatManager {

private:
    set<int> seats;

public:
    SeatManager(int n) {

        for(int i = 1; i <= n; i ++)
            seats.insert(i);
    }

    int reserve() {

        int seat = *seats.begin();
        seats.erase(seat);
        return seat;
    }

    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};


int main() {

    return 0;
}
