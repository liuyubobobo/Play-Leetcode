/// Source : https://leetcode.com/problems/intersection-of-three-sorted-arrays/
/// Author : liuyubobobo
/// Time   : 2019-10-06

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Tree Pointers
/// Time Complexity: O(|arr1| + |arr2| + |arr3|)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {

        vector<int> res;
        int i = 0, j = 0, k = 0;
        while(i < arr1.size() && j < arr2.size() && k < arr3.size()){
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k])
                res.push_back(arr1[i]), i ++, j ++, k ++;
            else if(arr1[i] <= arr2[j] && arr1[i] <= arr3[k]) i ++;
            else if(arr2[j] <= arr1[i] && arr2[j] <= arr3[k]) j ++;
            else k ++;
        }
        return res;
    }
};


int main() {

    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {1,2,5,7,9};
    vector<int> arr3 = {1,3,4,5,8};
    Solution().arraysIntersection(arr1, arr2, arr3);
    return 0;
}