/// Source : https://leetcode.com/problems/kth-missing-positive-number/
/// Author : liuyubobobo
/// Time   : 2021-01-06

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n + k)
/// Space Complexity: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int arrp = 0, e = 1;
        while(k){
            if(arrp < arr.size() && arr[arrp] == e) arrp ++;
            else k --;
            e ++;
        }
        return e - 1;
    }
};


int main() {

    vector<int> arr1 = {2, 3, 4, 7, 11};
    cout << Solution().findKthPositive(arr1, 5) << endl;
    // 9

    vector<int> arr2 = {1, 2, 3, 4};
    cout << Solution().findKthPositive(arr2, 2) << endl;
    // 6

    return 0;
}
