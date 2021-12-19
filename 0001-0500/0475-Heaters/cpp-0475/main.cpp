/// Source : https://leetcode.com/problems/heaters/
/// Author : liuyubobobo
/// Time   : 2021-12-19

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(max_pos))
/// Space Complexity: O(1)
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int l = 0, r = 1e9;
        while(l < r){
            int mid = (l + r) / 2;
            if(ok(houses, heaters, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& houses, const vector<int>& heaters, int r){

        int i = 0, j = 0;
        while(i < houses.size()){
            if(j >= heaters.size()) return false;
            if(heaters[j] - r <= houses[i] && houses[i] <= heaters[j] + r)
                i ++;
            else j ++;
        }
        return true;
    }
};


int main() {

    return 0;
}
