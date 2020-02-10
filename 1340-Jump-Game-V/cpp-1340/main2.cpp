/// Source : https://leetcode.com/problems/jump-game-v/
/// Author : liuyubobobo
/// Time   : 2019-02-10

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(nlogn + n * d)
/// Space Complexity: O(n)
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {

        vector<int> order;
        for(int i = 0; i < arr.size(); i ++) order.push_back(i);
        sort(order.begin(), order.end(), [arr](int a, int b){
            return arr[a] < arr[b];
        });
//        for(int e: order) cout << e << " "; cout << endl;

        vector<int> dp(arr.size(), 1);
        for(int pos: order){

            int maxv = arr[pos], maxi = pos;
            for(int i = pos - 1; i >= 0 && i >= pos - d; i --){
                if(arr[i] > maxv)
                    dp[i] = max(dp[i], 1 + dp[maxi]), maxv = arr[i], maxi = i;
            }

            maxv = arr[pos], maxi = pos;
            for(int i = pos + 1; i < arr.size() && i <= pos + d; i ++) {
                if (arr[i] > maxv)
                    dp[i] = max(dp[i], 1 + dp[maxi]), maxv = arr[i], maxi = i;
            }

//            cout << pos << " : ";
//            for(int e: dp) cout << e << " "; cout << endl;
        }

        return *max_element(dp.begin(), dp.end());
    }
};


int main() {

    vector<int> arr1 = {6,4,14,6,8,13,9,7,10,6,12};
    cout << Solution().maxJumps(arr1, 2) << endl;
    // 4

    vector<int> arr2 = {22,29,52,97,29,75,78,2,92,70,90,12,43,17,97,18,58,100,41,32};
    cout << Solution().maxJumps(arr2, 17) << endl;
    // 6

    return 0;
}
