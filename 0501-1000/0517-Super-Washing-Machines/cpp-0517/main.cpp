/// Source : https://leetcode.com/problems/super-washing-machines/
/// Author : liuyubobobo
/// Time   : 2020-04-07

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findMinMoves(vector<int>& machines) {

        int sum = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();

        if(sum % n) return -1;
        int avg = sum / n;
        for(int& e: machines) e -= avg;

        int res = *max_element(machines.begin(), machines.end()), cur = 0;
        for(int e: machines){
            cur += e;
            res = max(res, abs(cur));
        }
        return res;
    }
};


int main() {

    return 0;
}
