/// Source : https://leetcode.com/problems/destroying-asteroids/
/// Author : liuyubobobo
/// Time   : 2022-01-01

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());

        long long cur = mass;
        for(int e: asteroids)
            if(cur >= e) cur += e;
            else return false;
        return true;
    }
};


int main() {

    return 0;
}
