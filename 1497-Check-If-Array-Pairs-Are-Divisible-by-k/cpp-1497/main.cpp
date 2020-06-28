/// Source : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
/// Author : liuyubobobo
/// Time   : 2020-06-27

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        unordered_map<int, int> freq;
        for(int e: arr) freq[((e % k) + k) % k] ++;

        if(freq[0] % 2) return false;
        for(int i = 1; i + i < k; i ++)
            if(freq[i] != freq[k - i]) return false;

        if(k % 2 == 0 && freq[k / 2] % 2) return false;
        return true;
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
