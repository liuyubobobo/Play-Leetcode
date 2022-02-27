/// Source : https://leetcode.com/problems/minimum-time-to-complete-trips/
/// Author : liuyubobobo
/// Time   : 2022-02-26

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(n * log(MAXN))
/// Space Complexity: O(1)
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {

        long long l = 0, r = 1e14;
        while(l < r){
            long long mid = (l + r) / 2ll;
            if(ok(time, mid, totalTrips)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& time, long long mid, int totalTrips){
        long long res = 0;
        for(int t: time){
            res += mid / t;
            if(res >= totalTrips) break;
        }
        return res >= totalTrips;
    }
};


int main() {

    vector<int> time1 = {1, 2, 3};
    cout << Solution().minimumTime(time1, 5) << endl;
    // 3

    vector<int> time2 = {2};
    cout << Solution().minimumTime(time2, 1) << endl;
    // 2

    return 0;
}
