/// Source : https://leetcode.com/problems/sum-of-distances/description/
/// Author : liuyubobobo
/// Time   : 2023-04-09

#include <iostream>
#include <map>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); ++i) m[nums[i]].push_back(i);

        int n = nums.size();
        vector<long long> res(n);
        for(const pair<int, vector<int>>& p: m){
            const vector<int>& index_v = p.second;

            long long left_sum = 0, right_sum = 0, left_cnt = 0, right_cnt = index_v.size() - 1;
            for(int i = 1; i < (int)index_v.size(); i ++) right_sum += index_v[i] - index_v[0];
            res[index_v[0]] = left_sum + right_sum;

            for(int i = 1; i < (int)index_v.size(); i ++){
                long long d = index_v[i] - index_v[i - 1];
                left_sum += ++ left_cnt * d;
                right_sum -= right_cnt -- * d;
                res[index_v[i]] = left_sum + right_sum;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
