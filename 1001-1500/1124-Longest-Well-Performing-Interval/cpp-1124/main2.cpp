/// Source : https://leetcode.com/problems/longest-well-performing-interval/
/// Author : liuyubobobo
/// Time   : 2019-07-15

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Binary Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int longestWPI(vector<int>& hours) {

        for(int& e: hours)
            e = (e > 8 ? 1 : -1);

        int n = hours.size();
        vector<int> presum(n + 1, 0);
        for(int i = 1; i <= n; i ++)
            presum[i] = presum[i - 1] + hours[i - 1];

        int l = 0, r = n;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(ok(presum, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

private:
    bool ok(const vector<int>& presum, int len){

        int minv = INT_MAX;
        for(int i = 0; i + len < presum.size(); i ++){
            minv = min(minv, presum[i]);
            if(presum[i + len] - minv > 0)
                return true;
        }
        return false;
    }
};


int main() {

    vector<int> hours = {9,9,6,0,6,6,9};
    cout << Solution().longestWPI(hours) << endl;

    return 0;
}