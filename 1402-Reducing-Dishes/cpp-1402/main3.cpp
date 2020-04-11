/// Source : https://leetcode.com/problems/reducing-dishes/
/// Author : liuyubobobo
/// Time   : 2020-04-11

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn + n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(), satisfaction.end(), greater<int>());

        int n = satisfaction.size();
        int res = 0, sum = 0;
        for(int e: satisfaction){
            if(sum + e > 0) sum += e, res += sum;
            else break;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {-1,-8,0,5,-9};
    cout << Solution().maxSatisfaction(nums1) << endl;

    return 0;
}
