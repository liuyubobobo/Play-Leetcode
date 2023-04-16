/// Source : https://leetcode.com/problems/find-the-maximum-divisibility-score/description/
/// Author : liuyubobobo
/// Time   : 2023-04-15

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Brute Force
/// Time Complexity: O(|divisors| * log|divisors| + |nums| * |divisors|)
/// Space Complexity: O(1)
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {

        sort(divisors.begin(), divisors.end());
        int best = -1, res = -1;

        for(int d: divisors){
            int cnt = 0;
            for(int e: nums) cnt += (e % d == 0);
            if(cnt > best) best = cnt, res = d;
        }
        return res;
    }
};


int main() {

    return 0;
}
