/// Source : https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
/// Author : liuyubobobo
/// Time   : 2021-10-17

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {

        int n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int res = 0;
        for(int i = 0; i < n; i ++)
            res += abs(seats[i] - students[i]);
        return res;
    }
};


int main() {

    return 0;
}
