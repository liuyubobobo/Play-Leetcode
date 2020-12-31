/// Source : https://leetcode.com/problems/counting-elements/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Sorting and Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int countElements(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int res = 0;
        for(int e: arr){
            vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), e + 1);
            if(iter != arr.end() && *iter == e + 1)
                res ++;
        }
        return res;
    }
};


int main() {

    return 0;
}