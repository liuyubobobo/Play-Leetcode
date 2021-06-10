/// Source : https://leetcode.com/problems/cutting-ribbons/
/// Author : liuyubobobo
/// Time   : 2021-06-10

#include <iostream>
#include <vector>

using namespace std;


/// binary Search
/// Time Complexity: O(nlog(max_ribbons))
/// Space Complexity: O(1)
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {

        int l = 0, r = *max_element(ribbons.begin(), ribbons.end());
        while(l < r){

            int mid = (l + r + 1) / 2;

            if(ok(ribbons, mid, k)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& ribbons, int len, int k){

        int cnt = 0;
        for(int r: ribbons)
            cnt += r / len;
        return cnt >= k;
    }
};


int main() {

    return 0;
}
