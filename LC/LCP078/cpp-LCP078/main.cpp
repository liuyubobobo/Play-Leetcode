/// Source : https://leetcode.cn/problems/Nsibyl/
/// Author : liuyubobobo
/// Time   : 2023-05-07

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(max_rampart))
/// Space Complexity: O(1)
class Solution {
public:
    int rampartDefensiveLine(vector<vector<int>>& rampart) {

        int n = rampart.size(), l = 0, r = 1e8;
        while(l < r){
            int mid = l + (r - l + 1) / 2;
            if(ok(n, rampart, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(int n, vector<vector<int>> segs, int k){
        int r = segs[0][1];
        for(int i = 1; i < n; i ++){
            int a = segs[i][0], b = segs[i][1];
            if(a < r) return false;

            int left = a - r;
            if(left >= k) r = b;
            else r = b + (k - left);
        }
        return true;
    }
};


int main() {

    return 0;
}
