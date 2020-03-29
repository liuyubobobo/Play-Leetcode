/// Source : https://leetcode.com/problems/four-divisors/
/// Author : liuyubobobo
/// Time   : 2020-03-21

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * sqrt(num))
/// Space Complexity: O(1)
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int res = 0;
        for(int num: nums){
            int x = 0;
            if(ok(num, x)) res += x;
        }
        return res;
    }

private:
    bool ok(int num, int& res){

        int cnt = 2;
        res += 1 + num;
        for(int x = 2; x * x <= num; x ++)
            if(num % x == 0){
                if(x * x == num) return false;
                res += (x + num / x);
                cnt += 2;
                if(cnt > 4) return false;
            }
        return cnt == 4;
    }
};


int main() {

    vector<int> nums1 = {21, 4, 7};
    cout << Solution().sumFourDivisors(nums1) << endl;

    return 0;
}
