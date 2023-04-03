/// Source : https://leetcode.com/problems/minimum-time-to-eat-all-grains/description/
/// Author : liuyubobobo
/// Time   : 2023-04-03

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogmlog(INT_MAX))
/// Space Complexity: O(n + m)
class Solution {
public:
    int minimumTime(vector<int>& hens, vector<int>& grains) {

        sort(hens.begin(), hens.end());
        sort(grains.begin(), grains.end());

        int l = 0, r = INT_MAX;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(check(hens, grains, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool check(const vector<int>& hens, const vector<int>& grains, int k){

        int gi = 0;
        for(int hen: hens){

            if(grains[gi] < hen){
                if(hen - grains[gi] > k) return false;
                gi = get_max_gi(grains, gi, hen, k);
            }
            else{
                gi = upper_bound(grains.begin(), grains.end(), hen + k) - grains.begin();
            }

            if(gi >= grains.size()) break;
        }
        return gi == grains.size();
    }

    int get_max_gi(const vector<int>& grains, int gi, int hen, int k){

        assert(hen > grains[gi]);
        int gi1 = upper_bound(grains.begin(), grains.end(), hen + (k - 2 * (hen - grains[gi]))) - grains.begin();
        int gi2 = upper_bound(grains.begin(), grains.end(), hen + (k - (hen - grains[gi])) / 2) - grains.begin();
        return max(gi1, gi2);
    }
};


int main() {

    vector<int> hen1 = {0}, grain1 = {1000000000};
    cout << Solution().minimumTime(hen1, grain1) << '\n';

    return 0;
}
