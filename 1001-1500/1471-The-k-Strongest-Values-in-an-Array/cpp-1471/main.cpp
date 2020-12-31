/// Source : https://leetcode.com/problems/the-k-strongest-values-in-an-array/
/// Author : liuyubobobo
/// Time   : 2020-06-06

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());
        int mid = arr[(arr.size() - 1) / 2];
        sort(arr.begin(), arr.end(), [mid](int a, int b){
           if(abs(a - mid) != abs(b - mid))
               return abs(a - mid) > abs(b - mid);
           return a > b;
        });
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};


int main() {

    return 0;
}
