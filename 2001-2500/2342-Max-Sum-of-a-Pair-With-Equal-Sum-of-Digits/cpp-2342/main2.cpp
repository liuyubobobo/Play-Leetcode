/// Source : https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
/// Author : liuyubobobo
/// Time   : 2022-07-16

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


/// Using Map, no sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumSum(vector<int>& nums) {

        map<int, pair<int, int>> f;
        for(int e: nums){
            int sum = dsum(e);
            auto iter = f.find(sum);
            if(iter == f.end()) f[sum] = {e, -1};
            else if(e > iter->second.first){
                iter->second.second = iter->second.first;
                iter->second.first = e;
            }
            else{
                iter->second.second = max(e, iter->second.second);
            }
        }

        int res = -1;
        for(const pair<int, pair<int, int>>& p: f){
            if(p.second.second != -1){
                res = max(res, p.second.first + p.second.second);
            }
        }
        return res;
    }

private:
    int dsum(int x){
        int res = 0;
        while(x){
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};


int main() {

    return 0;
}
