/// Source : https://leetcode.com/problems/minimum-time-to-repair-cars/description/
/// Author : liuyubobobo
/// Time   : 2023-03-25

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(LONG_LONG_MAX))
/// Space Complexity: O(1)
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {

        long long l = 0, r = LONG_LONG_MAX;
        while(l < r){
            long long mid = l + (r - l) / 2;
            if(check(ranks, cars, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool check(vector<int>& ranks, int cars, long long time){

        long long max_cars = 0;
        for(int r: ranks){
            long long x = (long long)sqrt((long double)time / r);
            max_cars += x;
        }
        return max_cars >= cars;
    }
};


int main() {

    return 0;
}
