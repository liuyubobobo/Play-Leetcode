/// Source : https://leetcode.com/problems/minimum-money-required-before-transactions/description/
/// Author : liuyubobobo
/// Time   : 2023-01-09

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {

        vector<pair<int, int>> neg, pos;
        for(const vector<int>& e: transactions) {
            if (e[0] > e[1]) neg.push_back({e[0], e[1]});
            else pos.push_back({e[0], e[1]});
        }

        sort(neg.begin(), neg.end(), [](const pair<int, int>& e1, const pair<int, int>& e2){
            if(e1.second != e2.second) return e1.second < e2.second;
            return e1.first > e2.first;
        });

        sort(pos.begin(), pos.end(), [](const pair<int, int>& e1, const pair<int, int>& e2){
            return e1.first > e2.first;
        });

        long long res = 0, cur = 0;
        for(const pair<int, int>& e: neg){
            cur -= e.first;
            res = max(res, -cur);
            cur += e.second;
        }
        if(!pos.empty()) cur -= pos[0].first;
        return max(res, max(0ll, -cur));
    }
};


int main() {

    return 0;
}
