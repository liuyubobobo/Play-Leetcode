/// Source : https://leetcode.com/problems/prime-in-diagonal/description/
/// Author : liuyubobobo
/// Time   : 2023-04-09

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Brute Force
/// Time Complexity: O(nlogn + n * sqrt(max_num))
/// Space Complexity: O(n)
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {

        int n = nums.size();

        vector<int> v;
        for(int i = 0; i < n; i ++)
            v.push_back(nums[i][i]), v.push_back(nums[i][n - i - 1]);
        sort(v.begin(), v.end(), greater<>());

        for(int e: v) if(is_prime(e)) return e;
        return 0;
    }

private:
    bool is_prime(int x){
        if(x < 2) return false;
        for(int i = 2; i * i <= x; i ++)
            if(x % i == 0) return false;
        return true;
    }
};


int main() {

    return 0;
}
