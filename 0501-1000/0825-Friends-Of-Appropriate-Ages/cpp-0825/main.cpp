/// Source : https://leetcode.com/problems/friends-of-appropriate-ages/
/// Author : liuyubobobo
/// Time   : 2021-12-26

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n + max_age)
/// Space Complexity: O(max_age)
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {

        vector<int> presum(121, 0);
        for(int age: ages) presum[age] ++;
        for(int i = 1; i <= 120; i ++) presum[i] += presum[i - 1];

        int res = 0;
        for(int age = 1; age <= 120; age ++){
            int l = age / 2 + 7 + 1, r = age;
            if(age < 100) r = min(100, r);
            if(l > r) continue;

            int t = presum[r] - presum[l - 1];
            if(l <= age && age <= r) t --;
            res += (presum[age] - presum[age - 1]) * t;
        }
        return res;
    }
};


int main() {

    return 0;
}
