/// Source : https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/
/// Author : liuyubobobo
/// Time   : 2022-07-31

#include <iostream>
#include <vector>

using namespace std;


/// Greedy + Binary Search
/// Time Complexity: O(log(n))
/// Space Complexity: O(1)
class Solution {
public:
    int maximumGroups(vector<int>& grades) {

        int n = grades.size();
        int l = 1, r = n;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if((1ll + mid) * mid / 2 <= n) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};


int main() {

    vector<int> x = {10,6,12,7,3,5};
    cout << Solution().maximumGroups(x) << '\n';
    // 3

    return 0;
}
