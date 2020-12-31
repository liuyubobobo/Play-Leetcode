/// Source : https://leetcode.com/problems/average-waiting-time/
/// Author : liuyubobobo
/// Time   : 2020-12-26

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        long long cur = (long long)customers[0][0], total = 0ll;
        for(const vector<int>& e: customers){
            cur = max((long long)e[0], cur) + e[1];
            total += (cur - e[0]);
        }
        return (double)total / customers.size();
    }
};


int main() {

    vector<vector<int>> customers1 = {{5,2},{5,4},{10,3},{20,1}};
    cout << Solution().averageWaitingTime(customers1) << endl;

    return 0;
}
