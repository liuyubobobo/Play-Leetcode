/// Source : https://leetcode.com/problems/find-k-closest-elements/
/// Author : liuyubobobo
/// Time   : 2021-07-01

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn + klogk)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        sort(arr.begin(), arr.end(), [&](int a, int b){
            if(abs(a - x) != abs(b - x)) return abs(a - x) < abs(b - x);
            return a < b;
        });

        vector<int> res = vector<int>(arr.begin(), arr.begin() + k);
        sort(res.begin(), res.end());
        return res;
    }
};


int main() {

    return 0;
}
