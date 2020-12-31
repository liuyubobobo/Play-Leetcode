/// Source : https://leetcode.com/problems/count-number-of-teams/
/// Author : liuyubobobo
/// Time   : 2020-03-28

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    int numTeams(vector<int>& rating) {

        int res = 0;
        for(int i = 0; i < rating.size(); i ++)
            for(int j = i + 1; j < rating.size(); j ++)
                for(int k = j + 1; k < rating.size(); k ++)
                    res += (rating[i] > rating[j] && rating[j] > rating[k]) ||
                           (rating[i] < rating[j] && rating[j] < rating[k]);
        return res;
    }
};


int main() {

    return 0;
}
