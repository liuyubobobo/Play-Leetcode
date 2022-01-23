/// Source : https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
/// Author : liuyubobobo
/// Time   : 2022-01-22

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int numberOfWays(string corridor) {

        int n = corridor.size();
        vector<int> total_seats(n);
        total_seats[0] = corridor[0] == 'S';
        for(int i = 1; i < n; i ++)
            total_seats[i] = total_seats[i - 1] + (corridor[i] == 'S');

        if(total_seats.back() & 1) return 0;
        if(total_seats.back() <= 1) return 0;
//        if(total_seats.back() == 2) return 1;

        long long res = 1;
        int cur = 2;
        while(cur != total_seats.back()){
            int l = lower_bound(total_seats.begin(), total_seats.end(), cur) - total_seats.begin();
            int r = lower_bound(total_seats.begin(), total_seats.end(), cur + 1) - total_seats.begin();
            res *= (r - l);
            res %= MOD;

            cur += 2;
        }
        return res;
    }
};


int main() {

    string corridor1 = "SSPPSPS";
    cout << Solution().numberOfWays(corridor1) << endl;
    // 3

    string corridor2 = "PPSPSP";
    cout << Solution().numberOfWays(corridor2) << endl;
    // 1

    string corridor3 = "S";
    cout << Solution().numberOfWays(corridor3) << endl;
    // 0

    return 0;
}
