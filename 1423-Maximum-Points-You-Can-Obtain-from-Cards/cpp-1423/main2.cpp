/// Source : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
/// Author : liuyubobobo
/// Time   : 2020-04-27

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k == n) return sum;

        int window = 0, l = 0, r = -1, res = 0;
        while(r + 1 < n){
            window += cardPoints[++r];
            if(r - l + 1 == n - k)
                res = max(res, sum - window), window -= cardPoints[l++];
        }
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
