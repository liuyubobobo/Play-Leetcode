/// Source : https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/
/// Author : liuyubobobo
/// Time   : 2022-02-12

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return 0;

        unordered_map<int, int> sen, others;
        for(int i = 0; i < n; i ++) {
            if (i % 2 == 0) sen[nums[i]]++;
            else others[nums[i]]++;
        }

        vector<pair<int, int>> sen_v, others_v;
        for(const pair<int, int>& p: sen)
            sen_v.push_back({p.second, p.first});
        for(const pair<int, int>& p: others)
            others_v.push_back({p.second, p.first});

        sort(sen_v.begin(), sen_v.end(), greater<pair<int, int>>());
        sort(others_v.begin(), others_v.end(), greater<pair<int, int>>());

        int sen_num = (n + 1) / 2, others_num = n - sen_num;
        int res = n;
        if(sen_v[0].second != others_v[0].second){
            res = min(res, n - sen_v[0].first - others_v[0].first);
        }
        else{
            if(others_v.size() >= 2)
                res = min(res, n - sen_v[0].first - others_v[1].first);
            else res = min(res, n - sen_v[0].first);

            if(sen_v.size() >= 2)
                res = min(res, n - sen_v[1].first - others_v[0].first);
            else res = min(res, n - others_v[0].first);
        }

        return res;
    }
};


int main() {

    return 0;
}
