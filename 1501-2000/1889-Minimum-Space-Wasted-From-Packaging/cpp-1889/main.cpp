/// Source : https://leetcode.com/problems/minimum-space-wasted-from-packaging/
/// Author : liuyubobobo
/// Time   : 2021-06-05

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn + mlogm + mlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {

        sort(packages.begin(), packages.end());

        int n = packages.size();
        vector<long long> presum(n + 1, 0ll);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + packages[i];

        long long res = LONG_LONG_MAX;
        for(vector<int>& box: boxes){

            sort(box.begin(), box.end());
            if(box.back() >= packages.back())
                res = min(res, solve(packages, presum, box));
        }
        return res == LONG_LONG_MAX ? -1 : res % (long long)(1e9 + 7);
    }

private:
    long long solve(const vector<int>& packages, const vector<long long>& presum,
                    const vector<int>& box){

        int cur = 0;
        long long res = 0ll;
        for(int b: box){
            vector<int>::const_iterator iter = upper_bound(packages.begin(), packages.end(), b);
            int index = iter - packages.begin();
            int num = index -  cur;
            res += (long long)b * num - (presum[index] - presum[cur]);
            cur = index;
        }
        return res;
    }
};


int main() {

    vector<int> packages1 = {2, 3, 5};
    vector<vector<int>> boxes1 = {{4, 8}, {2, 8}};
    cout << Solution().minWastedSpace(packages1, boxes1) << endl;
    // 6

    vector<int> packages2 = {2, 3, 5};
    vector<vector<int>> boxes2 = {{1, 4}, {2, 3}, {3, 4}};
    cout << Solution().minWastedSpace(packages2, boxes2) << endl;
    // -1

    vector<int> packages3 = {3, 5, 8, 10, 11, 12};
    vector<vector<int>> boxes3 = {{12}, {11, 9}, {10, 5, 14}};
    cout << Solution().minWastedSpace(packages3, boxes3) << endl;
    // 9

    return 0;
}
