/// Source : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
/// Author : liuyubobobo
/// Time   : 2020-06-28

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Sorting and Two Pointers
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        for(int& e: arr) e = (e % k + k) % k;
        sort(arr.begin(), arr.end());

        int l = 0;
        for(; l < arr.size() && arr[l] % k == 0; l ++);
        if(l % 2) return false;

        int r = arr.size() - 1;
        while(l < r){
            if((arr[l]  + arr[r]) % k) return false;
            l ++, r --;
        }
        return l > r;
    }
};


int main() {

    vector<int> arr1 = {1,2,3,4,5,10,6,7,8,9};
    cout << Solution().canArrange(arr1, 5) << endl;
    // 1

    vector<int> arr2 = {1,2,3,4,5,6};
    cout << Solution().canArrange(arr2, 7) << endl;
    // 1

    vector<int> arr3 = {1,2,3,4,5,6};
    cout << Solution().canArrange(arr3, 10) << endl;
    // 0

    vector<int> arr4 = {-10, 10};
    cout << Solution().canArrange(arr4, 2) << endl;
    // 1

    vector<int> arr5 = {-1,1,-2,2,-3,3,-4,4};
    cout << Solution().canArrange(arr5, 3) << endl;
    // 1

    return 0;
}
