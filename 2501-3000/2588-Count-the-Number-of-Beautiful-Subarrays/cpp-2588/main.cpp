/// Source : https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/
/// Author : liuyubobobo
/// Time   : 2023-03-13

#include <iostream>
#include <vector>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(max_num)
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {

        vector<int> records(1 << 20, 0);
        records[0] ++;
        long long res = 0;
        int x = 0;
        for(int e: nums){
            for(int p = 0; p < 20; p++){
                if((e >> p) & 1) x ^= (1 << p);
            }
            res += records[x];
            records[x] ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
