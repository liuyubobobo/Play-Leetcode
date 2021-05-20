/// Source : https://leetcode.com/problems/maximum-population-year/
/// Author : liuyubobobo
/// Time   : 2021-05-08

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * |death - birth|)
/// Space Complexity: O(max(death))
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        vector<int> people(2051, 0);
        for(const vector<int>& log: logs)
            for(int i = log[0]; i < log[1]; i ++)
                people[i] ++;

        int maxpeople = -1, res = 0;
        for(int i = 1950; i <= 2050; i ++)
            if(people[i] > maxpeople) res = i, maxpeople = people[i];
        return res;
    }
};


int main() {

    return 0;
}
