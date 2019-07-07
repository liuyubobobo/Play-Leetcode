/// Source : https://leetcode.com/problems/corporate-flight-bookings/
/// Author : liuyubobobo
/// Time   : 2019-07-06

#include <iostream>
#include <vector>

using namespace std;


/// Dealing with Interview
/// Start and Ending events
/// Time Complexity: O(|bookings| + n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int> res(n + 1, 0);
        for(const vector<int>& booking: bookings){
            res[booking[0] - 1] += booking[2];
            res[booking[1]] -= booking[2];
        }

        for(int i = 1; i <= n; i ++)
            res[i] += res[i - 1];
        res.pop_back();
        return res;
    }
};


int main() {

    return 0;
}