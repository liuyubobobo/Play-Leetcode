/// Source : https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
/// Author : liuyubobobo
/// Time   : 2022-07-16

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


/// Using Map
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumSum(vector<int>& nums) {

        map<int, vector<int>> f;
        for(int e: nums) f[dsum(e)].push_back(e);

        for(const pair<int, vector<int>>& p: f){
            int sum = p.first;
            sort(f[sum].begin(), f[sum].end(), greater<int>());
        }

        int res = -1;
        for(const pair<int, vector<int>>& p: f){
            if(p.second.size() >= 2){
                res = max(res, p.second[0] + p.second[1]);
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
