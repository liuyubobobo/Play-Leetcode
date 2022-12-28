/// Source : https://leetcode.com/problems/maximum-tastiness-of-candy-basket/description/
/// Author : liuyubobobo
/// Time   : 2022-12-26

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn + nlong(max_price - min_price))
/// Space Complexity: O(1)
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {

        sort(price.begin(), price.end());

        int n = price.size();
        int l = 0, r = price.back() - price[0];
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(ok(price, mid, k)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& v, int t, int k){

        int cnt = 1, cur = v[0];
        while(cnt < k){
            cur += t;
            auto iter = lower_bound(v.begin(), v.end(), cur);
            if(iter == v.end()) return false;
            cur = *iter;
            cnt ++;
        }
        return true;
    }
};


int main() {

    return 0;
}
