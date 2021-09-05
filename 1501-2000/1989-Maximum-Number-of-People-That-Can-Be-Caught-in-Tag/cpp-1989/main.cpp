/// Source : https://leetcode.com/problems/maximum-number-of-people-that-can-be-caught-in-tag/
/// Author : liuyubobobo
/// Time   : 2021-09-05

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {

        int n = team.size();

        int res = 0, l = 0;
        for(int i = 0; i < n; i ++)
            if(team[i]){
                l = max(l, i - dist);
                while(l <= min(i + dist, n - 1))
                    if(team[l] == 0){
                        res ++;
                        l ++;
                        break;
                    }
                    else l ++;
            }
        return res;
    }
};


int main() {

    return 0;
}
