/// Source : https://leetcode.com/problems/removing-minimum-number-of-magic-beans/
/// Author : liuyubobobo
/// Time   : 2022-02-12

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {

        int n = beans.size();

        sort(beans.begin(), beans.end());
        vector<long long> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + beans[i];

        long long res = presum.back();
        for(int i = 0; i < n; i ++){
            if(i && beans[i] == beans[i - 1]) continue;

            long long tres = presum[i];
            tres += presum[n] - presum[i] - (long long)(n - i) * beans[i];
            res = min(res, tres);
        }
        return res;
    }
};


int main() {

    vector<int> beans1 = {4, 1, 6, 5};
    cout << Solution().minimumRemoval(beans1) << endl;
    // 4

    vector<int> beans2 = {2, 10, 3, 2};
    cout << Solution().minimumRemoval(beans2) << endl;
    // 7

    return 0;
}
