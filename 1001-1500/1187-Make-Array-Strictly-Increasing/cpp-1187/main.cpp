/// Source : https://leetcode.com/problems/make-array-strictly-increasing/
/// Author : liuyubobobo
/// Time   : 2019-09-07

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Memory Search
/// Time Complexity: O(n*m*logm)
/// Space Complexity: O(n*m)
class Solution {

private:
    map<pair<int, int>, int> dp;

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        set<int> set;
        for(int e: arr2) set.insert(e);

        int res = go(arr1, vector<int>(set.begin(), set.end()), 0, -1);
        return res == INT_MAX ? -1 : res;
    }

private:
    int go(const vector<int>& arr1, const vector<int>& arr2, int index, int last){

        if(index == arr1.size()) return 0;
        pair<int, int> hash = make_pair(index, last);
        if(dp.count(hash)) return dp[hash];

        int res = INT_MAX;
        if(arr1[index] > last) res = min(res, go(arr1, arr2, index + 1, arr1[index]));

        vector<int>::const_iterator iter = upper_bound(arr2.begin(), arr2.end(), last);
        if(iter != arr2.end()){
            int i = iter - arr2.begin();
            int t = go(arr1, arr2, index + 1, arr2[i]);
            if(t != INT_MAX)
                res = min(res, 1 + t);
        }

        return dp[hash] = res;
    }
};


int main() {

    vector<int> a1 = {1, 5, 3, 6, 7}, b1 = {1, 3, 2, 4};
    cout << Solution().makeArrayIncreasing(a1, b1) << endl;
    // 1

    vector<int> a2 = {1, 5, 3, 6, 7}, b2 = {4, 3, 1};
    cout << Solution().makeArrayIncreasing(a2, b2) << endl;
    // 2

    vector<int> a3 = {1, 5, 3, 6, 7}, b3 = {1, 6, 3, 3};
    cout << Solution().makeArrayIncreasing(a3, b3) << endl;
    // -1
    return 0;
}