/// Source : https://leetcode.com/problems/maximum-xor-after-operations/
/// Author : liuyubobobo
/// Time   : 2022-06-25

#include <iostream>
#include <vector>

using namespace std;


/// bitwise
/// Time Compelxity: O(nlogA)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumXOR(vector<int>& nums) {

        int n = nums.size();

        vector<int> f(31, 0);
        for(int num: nums){
            for(int p = 30; p >= 0; p --)
                f[p] += ((num >> p) & 1);
        }

        int res = 0;
        for(int p = 30; p >= 0; p --)
            if(f[p]) res += (1 << p);
        return res;
    }
};


int main() {

    return 0;
}
