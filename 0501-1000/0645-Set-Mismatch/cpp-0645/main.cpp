/// Source : https://leetcode.com/problems/set-mismatch/
/// Author : liuyubobobo
/// Time   : 2021-03-02

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();

        vector<int> res(2);
        unordered_map<int, int> f;
        for(int e: nums){
            f[e] ++;
            if(f[e] == 2) res[0] = e;
        }

        for(int i = 1; i <= n; i ++)
            if(!f.count(i)) res[1] = i;

        return res;
    }
};


int main() {

    return 0;
}
