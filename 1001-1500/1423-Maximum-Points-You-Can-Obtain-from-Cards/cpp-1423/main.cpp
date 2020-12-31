/// Source : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
/// Author : liuyubobobo
/// Time   : 2020-04-25

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Postsum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + cardPoints[i];

        vector<int> postsum(n + 1, 0);
        for(int i = n - 1; i >= 0; i --) postsum[i] = postsum[i + 1] + cardPoints[i];

        int res = 0;
        for(int i = 0; i <= k; i ++)
            res = max(res, presum[i] + postsum[n - (k - i)]);
        return res;
    }
};


int main() {

    vector<int>cardPoints1 = {1,2,3,4,5,6,1};
    cout << Solution().maxScore(cardPoints1, 3) << endl;
    // 12

    vector<int>cardPoints2 = {2, 2, 2};
    cout << Solution().maxScore(cardPoints2, 2) << endl;
    // 4

    vector<int>cardPoints3 = {9,7,7,9,7,7,9};
    cout << Solution().maxScore(cardPoints3, 7) << endl;
    // 55

    vector<int>cardPoints4 = {1,1000,1};
    cout << Solution().maxScore(cardPoints4, 1) << endl;
    // 1

    vector<int>cardPoints5 = {1,79,80,1,1,1,200,1};
    cout << Solution().maxScore(cardPoints5, 3) << endl;
    // 202

    vector<int>cardPoints6 = {1};
    cout << Solution().maxScore(cardPoints6, 1) << endl;
    // 1

    return 0;
}
