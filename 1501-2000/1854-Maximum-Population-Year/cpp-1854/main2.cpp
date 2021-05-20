/// Source : https://leetcode.com/problems/maximum-population-year/
/// Author : liuyubobobo
/// Time   : 2021-05-19

#include <iostream>
#include <vector>

using namespace std;


/// Sweepline
/// Time Complexity: O(n)
/// Space Complexity: O(max(death))
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        vector<int> people(2051, 0);
        for(const vector<int>& log: logs)
            people[log[0]] ++, people[log[1]] --;

        int maxpeople = -1, res = 0, cur = 0;
        for(int i = 1950; i <= 2050; i ++){
            cur += people[i];
            if(cur > maxpeople) res = i, maxpeople = cur;
        }
        return res;
    }
};


int main() {

    vector<vector<int>> logs1 = {{1950,1961},{1960,1971},{1970,1981}};
    cout << Solution().maximumPopulation(logs1) << endl;

    return 0;
}
