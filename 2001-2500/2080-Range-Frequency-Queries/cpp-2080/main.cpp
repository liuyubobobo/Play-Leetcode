/// Source : https://leetcode.com/problems/range-frequency-queries/
/// Author : liuyubobobo
/// Time   : 2021-11-20

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: init: O(n)
///                  query: O(logn)
/// Space Complexity: O(maxa)
class RangeFreqQuery {

private:
    vector<vector<int>> f;

public:
    RangeFreqQuery(vector<int>& arr) : f(10001) {
        for(int i = 0; i < arr.size(); i ++)
            f[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {

        int l = lower_bound(f[value].begin(), f[value].end(), left) - f[value].begin();
        int r = upper_bound(f[value].begin(), f[value].end(), right) - f[value].begin();
        return max(r - l, 0);
    }
};


int main() {

    return 0;
}
